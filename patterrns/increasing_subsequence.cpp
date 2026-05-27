#include<iostream>
#include<vector>
using namespace std;
/* int solve(vector<int>& nums, int ind, int prev_i,int& n, vector<vector<int> >& dp){
    if(ind == n ) return 0;
    if(dp[ind][prev_i+1] != -1) return dp[ind][prev_i];
    int take = 0;
    if(prev_i == -1 || nums[ind] > nums[prev_i]) take = 1+solve(nums, ind+1, ind, n,dp);
    int nottake = solve(nums, ind+1, prev_i, n,dp);
    return dp[ind][prev_i] = max(take,nottake);
} */
 /* int main(){
    int n; 
    cin >> n;
    vector<int> nums(n);
    for(int i =0; i< n; i++) cin >> nums[i];
    vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
   // int ans = solve(nums,0,-1,n,dp);
   for(int i = n-1; i >= 0; i--){
    for(int j = i; j >= -1; j--){
        int len = dp[i+1][j+1];
        if(j == -1 || nums[i] > nums[j+1])
        len = max(len, 1+ dp[i+1][i+1]);
        dp[i][j+1] = len;
    }
   }
    cout << dp[0][0] << endl;
}  TLE AAGAYA*/
  

// TLe aagaya even from tabulation...
int main(){
    int n; 
    cin >> n;
    vector<int> nums(n);
    for(int i =0; i< n; i++) cin >> nums[i];
    vector<int> lis;
// new method... LIS vector may not be a valid subsequence but its length is always thr LIS length.
// samajh naa aaye dubara toh chatgpt pe dekhlio.
// this is not even dp, it works in O(nlogn) time complexity.
    for(int x : nums) {
        auto it = lower_bound(lis.begin(), lis.end(), x);

        if(it == lis.end())
            lis.push_back(x);
        else
            *it = x;
    }

    cout << lis.size();
}