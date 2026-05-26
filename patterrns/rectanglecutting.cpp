#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int mod = 1e9+7;
/* int solve(int a, int b, vector<vector<int> >& dp){
    if(a == b) return 0;
    if(dp[a][b] != -1) return dp[a][b];
    // i need to check for all the horizontal cuts now, they can vary from 1 to b-1..
   int ans = INT_MAX;
    for(int i =1; i<=b-1; i++){
        ans = min(ans,solve(a,b-i,dp)+ solve(a,i,dp)+1);
    }
    // now vertical cuts
    for(int i =1; i<= a-1; i++){
        ans = min(ans,solve(a-i,b,dp)+solve(i,b,dp)+1);
    }
    return dp[a][b] = ans;
} */
int main(){
    int a,b;
    cin >> a >> b;
    vector<vector<int> > dp(a+1, vector<int>(b+1,1e9));
    for(int i = 1; i<=a; i++){
        for(int j = 1; j<= b; j++){
            if(i == j) 
            {dp[i][j] = 0; continue;}
            // make horizontal cuts..
            for(int z =1; z<=i-1; z++){
        dp[i][j] = min(dp[i][j],dp[i-z][j]+ dp[z][j]+1);
    }
    for(int k =1; k<=j-1; k++){
        dp[i][j] = min(dp[i][j],dp[i][k]+ dp[i][j-k]+1);
    }
        }
    }
    cout << dp[a][b];
}