#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
int main(){
    ll n,m,k ;
    cin >> n >> m >> k;
    vector<vector<pair<ll,ll> > > adj(n+1);
    for(ll i =0; i<m; i++ ){
        ll a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    priority_queue<pair<ll,ll> , vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq;
    pq.push({0,1});
    vector<ll> cnt(n+1,0);
    vector<ll> ans;
    while(!pq.empty()){
        ll node = pq.top().second;
        ll dis = pq.top().first;
        pq.pop();
        if(cnt[node] >= k) continue;
        cnt[node]++;
        if(node == n){
            ans.push_back(dis);
            if(cnt[n] == k) break;
        }
        for(auto it : adj[node]){
            ll nxt = it.first;
            ll wt = it.second;
                pq.push({dis + wt, nxt});
            }
        }
    
    for(auto x :ans){
        cout << x << " ";
    }
}
