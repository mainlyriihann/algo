#include<iostream>
#include<vector>
using namespace std;
int mod = 1e9 + 7;
/* int solve(int ind, int target, vector<int>& coins, vector<vector<int>>& dp){
    if(target == 0) return 1;
    if(target <0) return 0;
    if(ind <0 && target >0 ) return 0;
    if(dp[ind][target] != -1) return dp[ind][target];
    if(ind == 0 && target%coins[ind] == 0) return 1;
    
    return dp[ind][target] = (solve(ind, target- coins[ind], coins, dp)+ solve(ind-1, target, coins,dp))%mod;
} */
int main()
{
    int n, target; 
    cin >> n >> target;
    vector<int> coins(n);
    for(int i =0; i< n; i++){
        cin >> coins[i];
    }
    vector<vector<int> > dp(n, vector<int>(target+1, 0));
    for(int i = 0; i< n; i++) dp[i][0] = 1;
    for(int i = 0; i<= target; i++){
        if( i % coins[0] == 0) dp[0][i] = 1;
        else dp[0][i] = 0;
    }
    for(int i = 1; i<n; i++){
        for(int j = 1; j<= target; j++){
            //not take case
            int nottake = dp[i-1][j];
            //take
            int take = 0;
            if(j >= coins[i]) take = dp[i][j-coins[i]];
            dp[i][j] = (take+nottake)%mod;
        }
    }
    cout << dp[n-1][target];
   
}