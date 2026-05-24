#include<iostream>
#include<vector>
using namespace std;
int mod = 1e9+7;
int solve(vector<vector<char> >& grid, int i, int j, vector<vector<int>>& dp){
    int n = grid.size();
    if(i == n-1 && j == n-1) return 1;
    if( i >= n || j>= n) return 0;
    if( grid[i][j] == '*') return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int moveright = solve(grid,i,j+1,dp);
    int movedown = solve(grid, i+1, j,dp);
    return dp[i][j] = (moveright+ movedown)%mod;
}
int main(){
    int n;
     cin>> n;
     vector<vector<char> > grid(n,vector<char>(n));
     vector<vector<int> > dp(n, vector<int>(n, -1));

     for(int i =0; i<n;i++){
        for(int j =0; j<n;j++){
            cin >> grid[i][j];
        }
     }
     if(grid[n-1][n-1] == '*') cout << 0;
    else{ int answer = solve(grid, 0,0,dp);
     cout << answer;
    }
}