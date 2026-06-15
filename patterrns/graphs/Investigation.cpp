#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
int mod= 1e9+7;
int main(){
    ll n,m;
    cin >> n >> m;
    vector<vector<pair<ll,ll> > > adj(n+1);
    for(ll i =0;i <m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    vector<ll> dist(n+1, 1e18);
    vector<ll> ways(n+1, 0);
    vector<ll> minflights(n+1, 1e18);
    vector<ll> maxflights(n+1, 0);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > q;
    q.push({0,1});
    dist[1] = 0;
    ways[1] = 1;
    minflights[1] = 0;
    maxflights[1] = 0;
    while(!q.empty()){
        ll node = q.top().second;
        ll dis = q.top().first;
        q.pop();
        if(dis > dist[node]) continue;
        for(auto it: adj[node]){
            ll nxt = it.first;
            ll wt = it.second;
            if(dis+wt < dist[nxt]){
                dist[nxt] = dis+wt;
                ways[nxt] = ways[node];
                minflights[nxt] = minflights[node]+1;
                maxflights[nxt] = maxflights[node]+1;
                q.push({dist[nxt],nxt});
            }
            else if(dis + wt == dist[nxt]){
                ways[nxt] =  (ways[nxt]+ways[node])%mod;
                minflights[nxt] = min(minflights[nxt], minflights[node]+1);
                maxflights[nxt] = max(maxflights[nxt], maxflights[node]+1);
            }
        }
    }
    cout << dist[n] << " " << ways[n] << " " << minflights[n] << " " << maxflights[n] << " ";
}