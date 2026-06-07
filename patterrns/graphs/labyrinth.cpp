#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int visited[1001][1001];
char parent[1001][1001];
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<char> > grid(n, vector<char>(m));
    for(int i =0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> grid[i][j];
        }
    }
    bool ans = false;
    queue<pair<int,int> > q; 
    int ar, ac;
    char dir[4] = {'R', 'D' , 'L', 'U'};
   memset(visited,-1, sizeof(visited));
    vector<vector<int> > dist(n, vector<int> (m, 1e9));
    for(int i =0; i<n; i++){
        for(int j =0; j< m; j++){
            if( grid[i][j] == 'A'){
                q.push({i,j});
                visited[i][j] = 1;
                dist[i][j] = 0;
                ar = i;
                ac = j;
            }
        }
    }
    int dr[4] = {0,1,0,-1};
    int dc[4] = {1,0,-1,0};
    int fr, fc;
    while(!q.empty()){
        int curr_r = q.front().first;
        int curr_c = q.front().second;
        q.pop();
        if(grid[curr_r][curr_c] == 'B'){
            ans = true; 
            fr = curr_r;
            fc = curr_c;
            break;
        }
       
        for(int k = 0; k< 4; k++){
            int nr = dr[k]+curr_r;
            int nc = dc[k]+curr_c;
            if(nr < n && nr >= 0 && nc < m && nc >= 0 && (grid[nr][nc] == '.' || grid[nr][nc] == 'B') && visited[nr][nc] == -1){
                
                dist[nr][nc] = min(dist[nr][nc],dist[curr_r][curr_c]+1);
                 visited[nr][nc] = 1;
                 parent[nr][nc] = dir[k];
                 q.push({nr,nc});
            }
        }
    }
    string path;
    int r, c; 
    r = fr; c = fc;
    while(!(r== ar && c == ac)){
        char move = parent[r][c];
        path.push_back(move);
        if(move == 'R') c--;
        else if(move == 'L') c++;
        else if(move == 'D') r--;
        else if( move == 'U') r++;
    }
    reverse(path.begin(), path.end());
   if(ans){
    cout << "YES" << endl << dist[fr][fc]<< endl << path;
   }
   else cout << "NO";
}