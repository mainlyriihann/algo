#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i =0; i< n; i++){
        cin >> grid[i];
    }
    vector<vector<int> > monstertime(n,vector<int>(m,1e9));
    pair<int,int> start;
    queue<pair<int,int>> q;
    for(int i =0; i< n; i++){
        for(int j =0; j< m; j++){
            if(grid[i][j] == 'M'){
                monstertime[i][j] = 0;
                q.push({i,j});
            }
            else if(grid[i][j] == 'A'){
                start = {i,j};
            }
        }
    }
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};
    char dir[4] = {'U', 'D', 'L', 'R'};
    while(!q.empty()){
        auto [r,c] = q.front();
        q.pop();
        for(int i =0; i<4; i++){
            int nr = r+dr[i];
            int nc = c+ dc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(grid[nr][nc] == '#') continue;
            if(monstertime[nr][nc] > monstertime[r][c] +1){
                monstertime[nr][nc] = monstertime[r][c] +1;
                q.push({nr,nc});
            }
        }
    }
    vector<vector<int> > dist(n, vector<int>(m, -1));
    vector<vector<char> > parent(n, vector<char>(m));
    queue<pair<int,int> > qu;
    pair<int,int> endcell = {-1,-1};
    qu.push(start);
    dist[start.first][start.second] = 0;
    while(!qu.empty()){
        auto [r,c] = qu.front();
        q.pop();
        if(r == 0 || r == n-1 || c == 0 || c == m-1){
            endcell = {r,c};
            break;
        }
        for(int i = 0; i< 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(grid[nr][nc] == '#') continue;
            if(dist[nr][nc] != -1) continue;
            int mytime = dist[r][c] +1;
            if(mytime >= monstertime[nr][nc]) continue;
            dist[nr][nc] = mytime;
            parent[nr][nc] = dir[i];
            qu.push({nr,nc});
        }
    }
    if(endcell.first == -1) cout << "NO";
    else{
        cout << "YES" << endl;
        string ans;
        int r = endcell.first;
        int c = endcell.second;
        while(make_pair(r,c) != start){
            char d = parent[r][c];
            ans.push_back(d);
        if(d == 'U') r++;
        else if(d == 'D') r--;
        else if(d == 'L') c++;
        else if(d == 'R') c--;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        cout << ans << endl;
    }
    return 0;
}