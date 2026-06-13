#include<iostream>
#include<vector>
#include<queue>
#include<algorithm> 
using namespace std;
bool dfs(int node, vector<vector<int> >& adj, vector<int>& parent, vector<int>& visited){
    visited[node] = 1;
    for(auto it: adj[node]){
        if(visited[it] == 0){
            parent[it] = node;
            dfs(it,adj,parent, visited);
        }
        else if(visited[it] && parent[node] != it){
            // cycle found..
            parent[it] = node;
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
    bool cycle;
    int start;
    for(int i =1; i<n+1; i++){
        
        if(visited[i] == 0){
             cycle = dfs(i,adj,parent,visited);
        }
        if(cycle) {start = i; break;}
    }
    if(!cycle) cout << "IMPOSSIBLE";
    else{ 
        vector<int> ans;
        int curr = start;
        bool flag = true;
        while(flag){
            ans.push_back(curr);
            int par = parent[curr];
            curr = parent[curr];
            if(curr == start) flag = false;
        }
        int d = ans.size();
        cout << d << endl;
        for(int i =0; i< d; i++){
            cout << ans[i] << " ";
        }
    }
}