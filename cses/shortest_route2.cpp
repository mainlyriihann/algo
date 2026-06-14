#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
int main(){
    ll n,m,q;
    cin >> n >> m >> q;
    vector<vector<ll> > mat(n+1, vector<ll>(n+1, 1e18));
    for(ll i =1; i<= n; i++){
        mat[i][i] = 0;
        }
        for(ll i =0; i< m; i++){
            ll a,b,c;
            cin >> a >> b >> c;
            mat[a][b] = min(mat[a][b],c);
            mat[b][a] = min(mat[b][a],c);
        }
        for(ll k = 1; k<= n; k++){
            for(ll j = 1; j<= n; j++){
                for(ll i = 1; i<=n; i++){
                    if(mat[i][k] < 1e18 && mat[k][j] < 1e18){
                    if(mat[i][k] + mat[k][j] < mat[i][j])
                    mat[i][j] = mat[i][k] + mat[k][j];
                    }
                }
            }
        }
        for(ll i =0; i< q; i++){
            ll a,b;
            cin >> a >> b;
            if(mat[a][b] != 1e18)
            cout << mat[a][b] << endl;
            else
            cout << -1 << endl;
        }
    }
