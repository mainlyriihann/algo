#include<iostream>
#include<vector>
using namespace std;
 /* int solve(int n, vector<int>& dp){
    if(n == 0) return 1;
    if(n< 0) return 0;
    if(dp[n] != -1) return dp[n];
    // explore all paths: 
    // all paths can be 1,2,3,4,5,6 that will be deducted from the target. 
    int tmp = 0;
    tmp = solve(n-1,dp)+ solve(n-2,dp)+solve(n-3,dp)+solve(n-4,dp)+solve(n-5,dp)+solve(n-6,dp);
    return dp[n] = tmp;
} */


// oopar memoized solution hai.
const int MOD = 1e9 + 7;
int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // base case
    for (int sum = 1; sum <= n; sum++) {
        for (int dice = 1; dice <= 6; dice++) {
            if (sum - dice >= 0) { // cant be negative
                dp[sum] = (dp[sum] + dp[sum - dice]) % MOD;
            }
        }
    }
    cout << dp[n];

} 