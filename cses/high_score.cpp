#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
void dfs(ll node, vector<bool>& canreachN, vector<vector<ll > >& rev, vector<int>& visited)
{
    canreachN[node] = true;
    visited[node] = 1;
    for(auto it: rev[node]){
        if(!visited[it])
        dfs(it,canreachN, rev, visited);
    }
    return;
}
int main(){
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll,ll> > > adj(n+1);
    vector<vector<ll > > rev(n+1);
    for(ll i =0; i<m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
       
        adj[a].push_back({b,c});
        rev[b].push_back(a);
    }
    vector<ll> dist(n+1, -1e18);
    dist[1] = 0;
    for(int k =0; k < n; k++){
        for(ll i = 1; i<= n; i++){
            ll node = i;
            for(auto it : adj[node]){
                ll nxt = it.first;
                ll wt = it.second;
                if(dist[node] != -1e18 && dist[node]+wt > dist[nxt])
                dist[nxt] = dist[node]+wt;
                }
            }
        }
    
    vector<ll> bad;
    for(ll i =1; i<= n; i++){
        ll node = i;
        for(auto it: adj[node]){
            ll nxt = it.first;
            ll wt = it.second;
            if(dist[node] != -1e18 && dist[node]+ wt > dist[nxt]){
                bad.push_back(nxt);
            }
        }
    }
    vector<int> visited(n+1, 0);
    vector<bool> canreachN(n+1, false);
    dfs(n, canreachN, rev, visited);
    for(ll i =0; i< bad.size(); i++){
        ll node = bad[i];
        if(canreachN[node]){
            cout << -1;
            return 0;
        }
    }
    
    cout << dist[n];
}
