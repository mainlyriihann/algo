#include<iostream>
#include<vector>
#include<set>
#include<numeric>
using namespace std;
void solve(vector<int>& s, vector<int>& nums, int i,int ans, vector<vector<int> >& dp){
  if(i<0) {s.push_back(ans);
    return;}
    if(dp[i][ans] == 1) return;
    dp[i][ans] = 1;
  // pick , non pick
   solve(s, nums, i-1, ans+ nums[i],dp);
  
   solve(s,nums,i-1, ans,dp);
}
int main(){
    int n; 
    cin>> n;
    vector<int> nums(n);
    for(int i =0; i<n; i++) cin >> nums[i];
    vector<int> s;
    int x = accumulate(nums.begin(),nums.end(),0);
    vector<vector<int> > dp(n, vector<int>(x+1,-1));
    solve(s, nums, n-1,0,dp);
   set<int> ss;
   for(int i =0; i< s.size(); i++){
    ss.insert(s[i]);
   }
   cout << ss.size()-1 << endl;
   for(auto it: ss) {
    if(it != 0)
    cout<< it << " ";
   }
}