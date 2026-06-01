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
     ll zor = 0;
    for(ll r = 0; r< n; r++){
        zor ^= nums[r];
        if(r >= k){
            zor ^= nums[r-k];
        }
        if(r >= k-1){
            ans ^= zor;
        }
    }
    cout << ans;
}