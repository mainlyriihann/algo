#include<iostream>
#include<vector>
using namespace std;
void dfs(int node, vector<vector<int> >& adj, vector<int>& visited){
    visited[node] = 1;
    for(auto it: adj[node]){
        if(visited[it] == 0){
            dfs(it,adj,visited);
            
        }
    }
    return;
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> > adj(n+1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
     vector<int> reps;
    int components = 0;
    vector<int> visited(n+1,0);
    for(int i =1; i<= n; i++){
        if(visited[i] == 0){
            reps.push_back(i);
            dfs(i, adj, visited);
            components++;
        }
    }
   
    cout << components-1 << endl;
    for(int i =1; i< reps.size(); i++){
    }
}