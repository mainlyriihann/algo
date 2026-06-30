#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
const int Log = 20;
void dfs(int node, int par, vector<vector< int> >& adj, vector<vector<ll> >& up, vector<int>& depth){
    up[node][0] = par;
    for(int i = 1; i< Log; i++){
        if(up[node][i-1] != -1){
            up[node][i] = up[up[node][i-1]][i-1];
        }
    }
    for(auto it: adj[node]){
        if(it != par){
            depth[it] = depth[node]+1;
            dfs(it,node,adj,up,depth);
        }
    }
    return;
}
int lift(int node, int k, vector<vector<ll> >& up){
    for(int i = 0; i< Log && node != -1; i++){
        if(k&(1<<i)){
            node = up[node][i];
        }
    }
    return node;
}
int find(int a, int b, vector<vector<ll> >& up){
    for(int i = Log-1; i>= 0; i--){
        if(up[a][i] != up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; 
    cin >> n >> q;
    vector<vector<ll> > up(n+1, vector<ll>(Log, -1));
    vector<vector<int> > adj(n+1);
    vector<int> depth(n+1,0);
    for(int i = 0; i < n-1; i++){
        int a, b; 
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1,adj,up,depth);
    for(int i = 0; i< q; i++){
        int a,b;
        cin >> a >> b;
        int u = a;
        int v = b;
        if(depth[a] < depth[b]){
            swap(a,b);}
            a = lift(a, depth[a]- depth[b], up);
            int lca ;
        if(a == b){
            lca = a;
        }
        else
         lca = find(a,b,up);
        cout << depth[u]+depth[v] - 2*(depth[lca]) << endl;
    }
    return 0;
}