#include<iostream>
#include<vector>
#include<queue>
#include<algorithm> 
using namespace std;
int cycle_start, cycle_end;
bool dfs(int node, vector<vector<int> >& adj, vector<int>& parent, vector<int>& visited){
    visited[node] = 1;
    for(auto it: adj[node]){
        if(it == parent[node]) continue;
        if(visited[it] == 0){
            parent[it] = node;
            if(dfs(it,adj,parent, visited))
            return true;
        }
        else {
            cycle_start = it;
            cycle_end = node;
            return true;
        }
    }
    return false;
}
int main(){
    int n,m ;
    cin >> n >> m;
    vector<vector<int> > adj(n+1);
    for(int i =0; i< m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> parent(n+1);
    vector<int> visited(n+1,0);
    for(int i = 1; i<= n; i++){
        parent[i] = i;
    }
    bool found;
    for(int i =1; i<n+1; i++){
        
        if(visited[i] == 0){
             found = dfs(i,adj,parent,visited);
        }
        if(found) break;
    }
    if(!found) cout << "IMPOSSIBLE";
    else{ 
        vector<int> cycle;
        int cur = cycle_end;
        cycle.push_back(cycle_start);
        while(cur != cycle_start){
           cycle.push_back(cur);
           cur = parent[cur];
        }
        cycle.push_back(cycle_start);

    reverse(cycle.begin(), cycle.end());
        int d = cycle.size();
        cout << d << endl;
        for(int i =0; i< d; i++){
            cout << cycle[i] << " ";
        }
    }
}