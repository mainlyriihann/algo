#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
ll Log = 20;
   
    
int main(){
    ll n, q;
    cin >> n >> q;
   
    vector<vector<ll> > up(n+1, vector<ll> (Log, -1));
    for(int i = 2; i< n+1; i++){
        int a; 
        cin >> a;
        up[i][0] = a;
        for(int j = 1; j< Log; j++){
            if(up[i][j-1] != -1){
                up[i][j] = up[up[i][j-1]][j-1];
            }
        }
    }
        
        for(int i = 0; i< q; i++){
            int x,k;
            cin >> x >>  k;
             for(int j = 0; j< Log; j++){
            if(x == -1) break;
            if(k&(1<<j)){
                x = up[x][j];
            }
        }
            cout << x << endl;
            }
            return 0;
        }
