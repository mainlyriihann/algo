#include<iostream>
#include<vector>
using namespace std;
int mod = 1e9+7;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    vector<vector<int> > dp(n, vector<int>( m+1, 0));
    // need to write the base case first, if arr[i] == 0 , then saare 1 honge.
    if(arr[0] == 0) {
        for(int i =1; i<=m; i++) dp[0][i] = 1;
    }
    else dp[0][arr[0]] = 1;

    // now, to fill dp table, i need to go from index 1 to n-1, and check which ones are zeroes, and konse non zer0 hai.
    for(int i = 1; i<n; i++){
        if(arr[i] == 0){
            for(int j = 1; j <= m; j++){
                dp[i][j] = dp[i-1][j];
                if(j-1 >= 0) dp[i][j] = (dp[i][j]+dp[i-1][j-1])%mod;
                if(j+1 <=m) dp[i][j] = (dp[i][j]+dp[i-1][j+1])%mod;
            }
        }
        else{
            int j = arr[i];
            dp[i][j] = dp[i-1][j];
                if(j-1 >= 0) dp[i][j] = (dp[i][j]+dp[i-1][j-1])%mod;
                if(j+1 <=m) dp[i][j] = (dp[i][j]+dp[i-1][j+1])%mod;
        }
    }
    // to get the result, i need to add the last index ki row values.
    int sum = 0;
    for(int i= 0; i<m+1; i++) sum = (sum+dp[n-1][i])%mod;
    cout << sum;
}