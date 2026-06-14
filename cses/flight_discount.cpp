#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
int main(){
    ll n,m;
    cin >> n >> m;
    vector<vector<pair<ll,ll> > > adj(n+1);
    for(ll i =0; i<m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    vector<vector< ll > > dist(n+1, vector<ll>(2, 1e18));
    dist[1][0] = 0;
    priority_queue<tuple<ll,ll,ll> , vector<tuple<ll,ll,ll> >, greater<> > pq;
    pq.push({0,1,0});
    // cost, node, state(used or unused)
    while(!pq.empty()){
        auto [cost, node, used] = pq.top();
        pq.pop();
        if(cost > dist[node][used]) continue;
        for(auto it: adj[node]){
            ll nxt = it.first;
            ll wt = it.second;
            if(used == 0){
                // discount not used yet, explore the possibilies.
                //dont use discount.
                if(cost + wt < dist[nxt][0]){
                    dist[nxt][0] = cost + wt;
                    pq.push({dist[nxt][0], nxt, 0});
                }
                // use discount
                if(cost + wt/2 < dist[nxt][1]){
                    dist[nxt][1] = cost + wt/2;
                    pq.push({dist[nxt][1], nxt, 1});
                }
            }
            else{
                // cannot use discount.
                if(cost + wt < dist[nxt][1]){
                    dist[nxt][1] = cost + wt;
                    pq.push({dist[nxt][1], nxt, 1});
                }
            }
        }
    }
    cout << dist[n][1] << endl;
}