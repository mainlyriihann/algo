#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n+1);
    for(int i =0; i< m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    
    vector<int> par(n+1);
    for(int i =1; i< n+1; i++){
        par[i] = i;
    }
        vector<int> visited(n+1, 0);
        visited[1] =1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(node == n){
            break;
        }
        for(auto it: adj[node]){
            if(visited[it] == 0){
                visited[it] = 1;
                par[it] = node;
                q.push(it);
            }
        }
    }
    if(visited[n]){
    vector<int> ans;
    int curr = n;
    while(par[curr] != curr){
        ans.push_back(curr);
        curr = par[curr];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int j = 0; j< ans.size(); j++){
        cout << ans[j] << " ";
    }
}
else cout << "IMPOSSIBLE";

}