#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
int mod = 1e9+7;
   int max_n = 1e6;
int main(){
    int t;
    vector<vector<ll> > dp(max_n+1, vector<ll>(2,0));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i = 2; i<= max_n; i++){
        dp[i][0] = (4*dp[i-1][0] + dp[i-1][1])%mod;
        dp[i][1] = (2*dp[i-1][1] + dp[i-1][0])%mod;
    }
    cin >> t;
    for(int i =0; i<t; i++){
        int n;
        cin >> n;
        ll answer = (dp[n][0] + dp[n][1])%mod;
        cout<< answer << endl;
    }
   
}