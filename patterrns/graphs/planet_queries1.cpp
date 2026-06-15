#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,q;
    cin >> n >> q;
    vector<vector<int> > up(n+1, vector<int>(31));
    
        for(ll i = 1; i<=n; i++){
            cin >> up[i][0];
        }
    
    for(ll j =1; j<=30; j++){
        for(ll i =1; i<=n; i++){
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
    for(ll i = 1; i<=q; i++){
        ll x, k;
        cin >> x >> k;
        for(ll j = 0; j<= 30; j++){
            if(k&(1LL << j)){
                x = up[x][j];
            }
        }
        cout << x << '\n';
    }
}