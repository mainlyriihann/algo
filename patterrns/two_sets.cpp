#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
int mod = 1e9+7;
int solve(vector<int>& nums, int i, int curr, vector<vector<int> >& dp)
{   // base case
    if(curr == 0) return 1;
    if(curr <0) return 0;
    if(i == 0){
        if(nums[i] == curr) return 1;
        return 0;
    }
    if(dp[i][curr] != -1) return dp[i][curr];
    // take and not take case... 
    int take = 0;
    if(curr >= nums[i]) take = solve(nums, i-1, curr - nums[i],dp);
    int nottake = solve(nums, i-1,curr,dp);
    return dp[i][ curr] = (take+nottake)%mod;
    

}
int main(){
    int n;
     cin >> n;
     vector<int> nums(n);
     for(int i =0; i<n; i++) nums[i] = i+1;
    int answer;
    int sum = accumulate(nums.begin(), nums.end(),0);
    if (sum %2 != 0) answer = 0;
    else{
        int target = sum/2;
        vector<vector<int> > dp(n, vector<int>(target+1, -1));
        answer = solve(nums,n-1,target,dp);
    }
    cout << (1LL*answer*(500000004))%mod << endl;
}