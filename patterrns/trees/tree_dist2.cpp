#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
ll n;
vector<vector<ll> > adj;
vector<ll> sub,dp,ans;
void dfs1(ll node, ll par){
    sub[node] = 1;
    dp[node] = 0;
    for(ll nxt: adj[node]){
        if(nxt == par) continue;
        dfs1(nxt,node);
        sub[node] += sub[nxt];
        dp[node] += dp[nxt]+sub[nxt];
    }
}
void dfs2(ll node, ll par){
    for(ll nxt: adj[node]){
        if(nxt == par) continue;
        ans[nxt] = ans[node]+n - 2*sub[nxt];
        dfs2(nxt,node);
    }
}
int main(){
    cin >> n;
    adj.resize(n+1);
    sub.resize(n+1);
    dp.resize(n+1);
    ans.resize(n+1);
    for(int i = 0; i< n-1; i++){
        ll a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1,0);
    ans[1] = dp[1];
    dfs2(1,0);
    for(int i =1; i<= n; i++){
        cout << ans[i] << " ";
    }
}
