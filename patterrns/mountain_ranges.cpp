#include <iostream>
#include<vector>
using namespace std;
int n;
vector<long long> h;
vector<int> dp;

int solve(int i) {
    if(dp[i] != -1) return dp[i];
    int ans = 1;
    for(int j = i - 1; j >= 0 && h[j] < h[i]; j--) {
        ans = max(ans, 1 + solve(j));
    }
    for(int j = i + 1; j < n && h[j] < h[i]; j++) {
        ans = max(ans, 1 + solve(j));
    }
    return dp[i] = ans;
}
int main() {
    cin >> n;
    h.resize(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    dp.assign(n, -1);
    int ans = 1;
    for(int i = 0; i < n; i++) {
        ans = max(ans, solve(i));
    }
    cout << ans;
}