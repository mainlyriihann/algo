#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;
using ll = long long;
int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    for(ll i = 0; i< n; i++) cin >> nums[i];
    vector<ll> ans;
    unordered_map<ll,ll> freq; //use set-pair {-freq, number}
   set<pair<ll, ll> > st;
   for(ll r =0; r<n; r++){
    ll x = nums[r];
    if(freq[x] > 0) st.erase({-freq[x],x});
    freq[x]++;
    st.insert({-freq[x],x});
    if(r >= k){
        ll out = nums[r-k];
        st.erase({-freq[out], out});
        freq[out]--;
        if(freq[out] > 0) st.insert({-freq[out],out});
        else freq.erase(out);
    }
    if(r >= k-1){
        ans.push_back(st.begin()->second);
    }
   }
   ll d = ans.size();
   for(ll i = 0; i<d; i++){
    cout << ans[i] << " ";
   }
}