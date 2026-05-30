#include<iostream>
#include<vector>
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
     ll ans = 0;
     vector<ll> pre(n);
     pre[0] = nums[0];
     for(ll i =1; i<n; i++){
        pre[i] = pre[i-1] + nums[i];
     }  

     for(ll l =0; l+k-1 < n; l++){
      ll r = l+k-1;
     ll sum = pre[r];
      if(l>0) sum = sum - pre[l-1];
      ans ^= sum;
     }
     cout << ans;
}