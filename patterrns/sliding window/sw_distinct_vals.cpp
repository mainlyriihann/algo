#include<iostream>
#include<vector>
#include<map>
using namespace std;
using ll = long long;
int main(){
    ll n,k;
    cin >> n >> k;
    vector<ll> nums(n);
    for(ll i =0; i<n; i++) cin >> nums[i];
    map<ll,ll> mpp;
    vector<ll> ans;
    for(ll r =0; r< n; r++){
        mpp[nums[r]]++;
        if(r >= k){
            mpp[nums[r-k]]--;
            if(mpp[nums[r-k]] == 0) mpp.erase(nums[r-k]);
        }
        if(r >= k-1){
            ans.push_back(mpp.size());
        }
    }
    ll d = ans.size();
    for(ll i =0; i< d; i++) cout << ans[i] << " ";
}