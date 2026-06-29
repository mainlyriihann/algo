#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
const ll Log = 20;


int lift(int node, int k, vector<vector<ll> >& up){
    for(int j = 0; j< Log-1; j++){
        if(node == -1) return -1;
        if(k&(1<<j)) node = up[node][j];
    }
    return node;
}
    
int main(){
    ll n, q;
    cin >> n >> q;
   
    vector<vector<ll> > up(n+1, vector<ll> (Log, -1));
    vector<int> depth(n+1, 0);
    for(int i = 2; i< n+1; i++){
        int a; 
        cin >> a;
        depth[i] = depth[a]+1;
        up[i][0] = a;
        for(int j = 1; j< Log; j++){
            if(up[i][j-1] != -1){
                up[i][j] = up[up[i][j-1]][j-1];
            }
        }
    }
        for(int i =0; i< q; i++){
            int a,b;
            cin >> a >> b;
            if(depth[a] < depth[b]){
                swap(a,b);
            }
           a = lift(a, depth[a]-depth[b],up);
            if(a == b) {
                cout << a << endl;
                continue;
            }
            for(int j = Log-1; j >=0 ; j--){
                if(up[a][j] != up[b][j]){
                    a = up[a][j];
                    b = up[b][j];
                }
            }
            cout << up[a][0] << endl;
        }
        
        }
