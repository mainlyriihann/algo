#include<iostream>
#include<vector>
#include<deque>
using namespace std;
using ll = long long;
int main(){
    ll n,k;
    cin >> n >> k;
    vector<ll> nums(n);
     ll x, a,b,c;
     cin >> x >> a >> b >> c;
     nums[0] = x;
     for(ll i =1; i<n; i++){
        nums[i] = ((1LL*a*(nums[i-1]))+b)%c;
     }
     vector<ll> ans;
     deque<ll> dq;
        for(ll i =0; i<n; i++){
            // remove from front, if window over:
            if(!dq.empty() && dq.front() <= i-k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()] > nums[i])
            dq.pop_back();
            dq.push_back(i);
            if(!dq.empty() && i >= k-1)
            ans.push_back(nums[dq.front()]);
        }
      ll sum = 0;
      ll f = ans.size();
      for(ll i = 0; i < f; i++){
        sum ^= ans[i];
      }
      cout << sum;
    }