#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*int solve(string& s1, string& s2, int i, int j){
    if(i <0 && j <0) return 0;
    if(i<0) { return j+1;
    }
    if(j <0) return i+1;
    // if both characters are same, 
    
    if(s1[i] == s2[j]) return solve(s1,s2,i-1,j-1);
    int insertop = 1+solve(s1,s2,i,j-1);
    int deleteop = 1+ solve(s1,s2,i-1,j);
    int replaceop = 1+solve(s1,s2,i-1,j-1);
    return min(insertop, min(deleteop, replaceop)); */

int main(){
    string s1; string s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
    for(int i =1; i< n+1; i++) dp[i][0] = i;
    for(int j =1; j< m+1; j++) dp[0][j] = j;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                int ins = 1+dp[i][j-1];
                int del = 1+dp[i-1][j];
                int rep = 1+dp[i-1][j-1];
                dp[i][j] = min(ins, min(del,rep));
            }
        }
    }
    //int answer = solve(s1,s2,n-1,m-1);
    cout << dp[n][m];
}