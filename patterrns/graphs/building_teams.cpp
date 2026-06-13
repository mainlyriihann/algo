#include<iostream>
#include<vector> 
#include<queue>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
     cin >> n >> m;
     vector<vector<int> > adj(n+1);
     vector<int> team(n+1);
     vector<int> visited(n+1,-1);
     for(int i =0; i< m; i++){
        int a,b ;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
     }
     bool flag = true;
     for(int i = 1; i< n+1; i++){
     if(visited[i]== 1) continue;
     visited[i] = 1;
     queue<int> q;
     q.push(i);
     team[i] = 1;
     while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it: adj[node]){
            if(visited[it] == -1){
                visited[it] = 1;
                team[it] = !team[node];
                q.push(it);
            }
            else if( team[it] == team[node]){
                flag = false;
                break;
            }
        }
        if(flag == false) break;
     }
    }
    if(flag){
     for(int i =1; i< n+1; i++){
        if(team[i] == 0) cout << "2" << " ";
        else cout << "1" << " ";
     }
    }
    else cout << "IMPOSSIBLE";
}