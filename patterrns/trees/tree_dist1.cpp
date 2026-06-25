#include<iostream>
#include<vector>
using namespace std;
using vvi = vector<vector<int> > ;
int maxDist;
void dfs(int node, int parent, int dist, vvi& adj, vector<int>& distt){
    distt[node] = dist;
    for(int nxt : adj[node]){
        if(nxt != parent)
        dfs(nxt,node,dist+1,adj,distt);
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
   
    // to get A, i need to find A..
    vector<int> dist_temp(n+1,0);
    dfs(1,0,0,adj,dist_temp);
    
    int A = 1;
    for(int i =1; i<= n; i++){
        if(dist_temp[i] > dist_temp[A])
        A = i;
    }
   vector<int> dist_A(n+1,0);
   dfs(A,0,0,adj,dist_A);
   int B = 1;
   for(int i = 1; i<= n; i++){
    if(dist_A[i] > dist_A[B])
    B = i;
   }
   vector<int> dist_B(n+1,0);
   dfs(B,0,0,adj,dist_B);
   for(int i = 1; i<= n; i++){
    cout << max(dist_A[i], dist_B[i]) << " ";
   }

}