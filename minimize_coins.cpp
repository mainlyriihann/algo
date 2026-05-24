#include<iostream>
#include<vector>
#include<climits>
using namespace std;
 /* int solve(vector<int>& coins, int target, int ind, vector<vector<int> >& dp){
    if(target == 0) return 0;
    if(ind == 0){
    if(target % coins[0] == 0)
        return target / coins[0];

    return 1e9;
}
    if(dp[ind][target] != -1) return dp[ind][target];
    // base case hogaye, now: 
    // explore the paths bruh, take a coin or not take a coin.
    // not take case: 
    int nottake = 0+ solve(coins, target, ind-1,dp);
    int take = 1e9;
    if(coins[ind] <= target) take = 1+solve(coins, target- coins[ind], ind,dp);

    return dp[ind][target] = min(nottake, take);

} */
int main(){
    int n; int target;
    cin>> n >> target;
    vector<int> coins(n);
    for(int i =0; i<n; i++) cin>> coins[i];
    vector<vector<int> > dp(n, vector<int>(target+1,1e9));

   // int ans = solve(coins, target, n-1,dp);
  //if (ans >= 1e9) cout << -1;
    //else cout << ans;
  // base case -> ind == 0, target == 0
  for(int i =0; i<n ; i++) dp[i][0] = 0;
  for(int i = 0; i <= target; i++){
    if( i% coins[0] == 0) 
    dp[0][i] = i/coins[0];
  }
  for(int i = 1; i<n; i++){
    for(int j = 0;j<= target; j++){
            // not take case: 
            int nottake = dp[i-1][j];
            //take:
            int take = 1e9;
            if(j >= coins[i]) 
            take = 1+ dp[i][j-coins[i]];
            dp[i][j] = min(take,nottake);
            }
  }
    if(dp[n-1][target] != 1e9) cout << dp[n-1][target];
    else cout<< -1;

}