#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
int mod = 1e9+7;
int main(){
    ll n,m;
    cin >> n >> m;
    vector<vector<ll> > adj(n+1);
    for(ll i= 0; i< m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<ll> ways(n+1,0);
    vector<ll> indeg(n+1, 0);

    for(int i = 1; i<=n; i++){
        for(auto j : adj[i]){
            indeg[j]++;
        }
    }
    ways[1] = 1;
    queue<ll> q;
    for(int i = 1; i<=n; i++){
        if(indeg[i] == 0) q.push(i);
    }
    while(!q.empty()){
        ll node = q.front();
        q.pop();
        for(auto it: adj[node]){
           ways[it] = (ways[it]+ways[node])%mod;
           indeg[it]--;
           if(indeg[it] == 0) q.push(it);
        }
    }
    cout << ways[n];
}