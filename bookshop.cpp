#include<iostream>
#include<vector>
#include<climits>
using namespace std;
/*
int solve(vector<int>& prices, vector<int>& pages, int ind, int cost, vector<vector<int>>& dp){
    // base cases :
    if(ind < 0 )return 0;
    if(cost <= 0) return 0;
    if(ind == 0 && cost>= prices[0]) return pages[0];
    if(dp[ind][cost] != -1) return dp[ind][cost];
    
    // take case and not take case. 
    int take = INT_MIN;
    if(prices[ind] <= cost) take = pages[ind] + solve(prices,pages,ind-1, cost-prices[ind],dp);
    int nottake = solve(prices,pages,ind-1, cost, dp);
    return dp[ind][cost] = max(take, nottake);
} */
int main(){
    int n, cost;
    cin >> n >> cost;
    vector<int> prices(n);
    for(int i =0; i< n;i++) cin >> prices[i];
    vector<int> pages(n);
    for(int i =0; i< n;i++) cin>> pages[i];
    vector<vector<int> > dp(n, vector<int> ( cost+1, 0));
    //int ans = solve(prices,pages,n-1,cost,dp);
    // base case: 
    // if cost == 0 or ind == 0
    for(int i =0; i<n ;i++) dp[i][0] = 0;
    for(int c = 0 ;c<= cost; c++) {
        if(prices[0] <= c){
            dp[0][c] = pages[0];
        }
    }
    for(int i =1; i<n; i++){
        for(int c = 1; c<=cost; c++){
            //explore niggeshwar. 
            // take case: 
            int take = 0;
            if(prices[i] <=c) take = pages[i] + dp[i-1][c-prices[i]];
            int nottake = dp[i-1][c];
            dp[i][c] = max(take,nottake);
        }
    }
    cout << dp[n-1][cost];
}