#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    int n; 
    cin >> n;
    vector<ll> nums(n);
    for(int i =0; i<n; i++) cin >> nums[i];

    vector<vector<ll> > dp(n, vector<ll>(n,0));
    for(int g =0; g<n; g++){
        for(int i = 0, j= g; i<n, j<n; i++, j++){
            if(g==0) dp[i][j] = nums[i];
            else if( g == 1) dp[i][j] = max(nums[i],nums[j]);
            else{
                ll val1 = nums[i] + min(dp[i+1][j-1], dp[i+2][j]);
                ll val2 = nums[j] + min(dp[i+1][j-1], dp[i][j-2]);
                dp[i][j] = max(val1,val2);
            }
        }

    }
    cout << dp[0][n-1] << endl;
}