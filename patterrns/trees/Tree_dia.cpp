#include<iostream>
#include<vector>
using namespace std;
using vvi = vector<vector<int> > ;
int maxDist;
int farthestNode;
void dfs(int node, int parent, int dist, vvi& adj){
    if(dist > maxDist){
        maxDist = dist;
        farthestNode = node;
    }
    for(int nei : adj[node]){
        if(nei != parent){
            dfs(nei, node, dist+1, adj);
        }
    }
    return;
}
int main(){
    int n;
    cin >> n;
    vvi adj(n+1);
    for(int i = 0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    maxDist = -1;
    dfs(1,0,0,adj);
    int A = farthestNode;
    maxDist = -1;
    dfs(A, 0,0,adj);
    cout << maxDist;
   
}