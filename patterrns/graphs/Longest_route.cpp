#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
using namespace std;
using ll = long long;
int main(){
    ll n,m;
    cin >> n >> m;
    vector<vector<int> > graph(n+1);
    for(int i =0; i< m; i++){
        ll u,v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    vector<int> indeg(n+1,0);
    for(int i = 1; i<= n; i++){
        for( int v : graph[i]){
            indeg[v]++;
        }
    }
    queue<int> q;
    for(int i =1; i<=n; i++){
        if(indeg[i] == 0) q.push(i);
    }
    vector<int> order;
    while(!q.empty()){
        int node = q.front(); 
        q.pop();
        order.push_back(node);
        for(auto it: graph[node]){
            indeg[it]--;
            if(indeg[it] == 0) q.push(it);
        }
    }
    vector<int> dist(n+1, -1e9);
    vector<int> parent(n+1,-1);
    dist[1] = 0;
    for(int i : order){
        if(dist[i] == -1e9) continue;
        for(int j : graph[i]){
            if(dist[j] < dist[i]+1){
                dist[j] = dist[i]+1;
                parent[j] = i;
            }
        }
    }
    if(dist[n] == -1e9) {cout << "IMPOSSIBLE";
        return 0;
    }
    int curr = n;
    vector<int> ans;
    while(true){
        ans.push_back(curr);
        curr = parent[curr];
        if(parent[curr] == -1) {
            break;
        }
    }
    ans.push_back(1);
    reverse(ans.begin(),ans.end());
    cout << ans.size()<< endl;
    for(auto i: ans){
        cout << i << " ";
    }
}