#include<iostream> 
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using ll = long long;
int main(){
    ll n,m;
    cin >> n >> m;
    vector<vector<pair<ll,ll> > > adj(n+1);
    for(ll i =0; i< m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    vector<ll> dist(n+1,1e18);
    dist[1] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll> > , greater<pair<ll,ll> > > q;
    q.push({0,1});
    while(!q.empty()){
        ll dis = q.top().first;
        ll node = q.top().second;
        q.pop();
        if(dis > dist[node]) continue;
        for(auto it: adj[node]){
            ll nxt = it.first;
            ll wt = it.second;
            if(dist[nxt] > dis+ wt){
                dist[nxt] = dis+wt;
                q.push({dist[nxt],nxt});
            }
        }
    }
    ll x = dist.size();
    for(ll i =1; i< x; i++){
        cout << dist[i] << " ";
    }
}