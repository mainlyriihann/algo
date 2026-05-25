#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/* int solve(vector<int>& arr1, vector<int>& arr2, int i, int j){
    if(i< 0 || j < 0) return 0;
    // match case:
     if(arr1[i] == arr2[j]) return 1+ solve(arr1,arr2,i-1,j-1);
    // not match case:
     int movei = solve(arr1,arr2,i-1,j);
     int movej = solve(arr1,arr2, i, j-1);
     return max(movei, movej);
} */
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n);
    for(int i =0; i<n; i++) cin >> arr1[i];
    vector<int> arr2(m);
    for(int j = 0; j< m; j++) cin >> arr2[j];

   // int answer = solve(arr1,arr2, n-1,m-1);
   vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
   for(int i = 1; i<=n; i++){
    for(int j = 1; j<=m; j++){
        // match case: 
        if(arr1[i-1] == arr2[j-1])
        dp[i][j] = 1+ dp[i-1][j-1];
        // not match case:
        else{
            int movei = dp[i-1][j];
            int movej = dp[i][j-1];
            dp[i][j] = max(movei, movej);
        }
    }
   }
   int i = n; int j = m;
   vector<int> tmp;
   while (i>0 && j>0){
    if(arr1[i-1] == arr2[j-1]){
        tmp.push_back(arr1[i-1]);
        i = i-1;
        j = j-1;
    }
    else{
        if(dp[i-1][j] >= dp[i][j-1]){
            i = i-1;
        }
        else j = j-1;
    }
   }
   int x = tmp.size();
   reverse(tmp.begin(), tmp.end());
    cout << dp[n][m] << endl;
    for(int i =0; i< x; i++){
        cout<< tmp[i] << " ";
    }
}