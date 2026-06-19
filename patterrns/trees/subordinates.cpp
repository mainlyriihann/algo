#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
int dfs(int node, vector<vector<int> >& adj, vector<int>& dp){
    int ans = 0;
    if(dp[node] != -1) return dp[node];
    for(auto it: adj[node]){
        ans += dfs(it,adj, dp)+1;
    }
    return dp[node] = ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> parent(n+1);
    vector<vector<int> > adj(n+1);
    for(int i = 2; i<=n; i++){
        int boss;
        cin >> boss;
        parent[i] = boss;
        adj[boss].push_back(i);
    }
    vector<int> dp(n+1,-1);
    for(int i = 1; i<= n; i++){
        cout << dfs(i,adj,dp) << " ";
    }
}