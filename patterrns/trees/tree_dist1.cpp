#include<iostream>
#include<vector>
using namespace std;
using vvi = vector<vector<int> > ;
int maxDist;
void dfs(int node, int parent, int dist, vvi& adj, vector<int>& dp){
    if(dist > maxDist){
        maxDist = dist;
        dp[node] = maxDist;
    }
    for(int nei : adj[node]){
        if(nei != parent){
            dfs(nei, node, dist+1, adj,dp);
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
    vector<int> dp(n+1, -1e9);
    for(int i = 1; i<=n; i++){
        maxDist = -1;
        dfs(i,0,0,adj,dp);
        cout << maxDist << " ";
    }
   
}