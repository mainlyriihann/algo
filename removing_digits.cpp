#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int solve(int target, vector<int>& dp){
        if(target == 0) return 0;
        if(dp[target] != -1) return dp[target];
        // to get each digit...
        int num = target;
        int ans  = INT_MAX;
        while(num > 0){
            int digit = num%10;
            num = num/10;
            if(digit != 0){
                ans = min(ans, 1+ solve(target-digit, dp));
            }
        }
        return dp[target]=ans;
    }


int main(){
    int n;
    cin>> n; 
    int x = n;
    vector<int> dp(n+1, -1);
    int ans = solve(n, dp);
    if(ans != INT_MAX)
    cout << ans;
}