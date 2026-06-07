#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int visited[1001][1001];
void dfs(int i, int j, vector<vector<char> >& grid, int n, int m){
    visited[i][j] = 1;
    int dr[4] = {0,1,0,-1};
    int dc[4] = {1,0,-1,0};
    for(int k =0; k<4; k++){
        int nr = dr[k] + i;
        int nc = dc[k] +j;
        if(nr < n && nr >= 0 && nc < m && nc >= 0 && grid[nr][nc] == '.' && visited[nr][nc] == -1){
            dfs(nr,nc,grid, n,m);
        }
    }
    return;
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<char> > grid(n, vector<char>(m));
    for(int i =0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> grid[i][j];
        }
    }
    int ans = 0;
   memset(visited,-1, sizeof(visited));
    for(int i =0; i<n; i++){
        for(int j =0; j< m; j++){
            if(visited[i][j] == -1 && grid[i][j] == '.'){
             dfs(i,j, grid,n,m);
            ans++;
            }
        }
    }
    cout << ans;
}