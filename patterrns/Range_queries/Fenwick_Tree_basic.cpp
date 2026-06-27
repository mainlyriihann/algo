#include<iostream> 
#include<vector>
using namespace std;
using ll = long long;
vector<ll> nums;
vector<ll>bit;
ll n,q;
void add(ll index, ll del){
    while(index <= n){
        bit[index] += del;
        index += (index&(-index));
    }
}
void update(int index, int val){
    ll del = val- nums[index];
    nums[index] = val;
    add(index, del);
}
ll query(int ind){
    ll sum = 0;
    for(ll i = ind; i >0 ; i -= (i&(-i))){
        sum += bit[i];
    }
    return sum;
}
ll sum(int a, int b){
    if(a == 0) return query(b);
    return query(b)-query(a-1);
}
int main(){
    
    cin >> n >> q;
    nums.assign(n+1,0);
    bit.assign(n+1,0);
    for(int i = 1; i<= n; i++){
        cin >> nums[i];
    }
    // make tree functional...
    for(ll i = 1; i<= n; i++){
        add(i, nums[i]);
    }
    for(ll i =0; i< q; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        if(a == 1){
            update(b,c);
        }
        else if(a==2){
            cout << sum(b,c) << endl;
        }
    }
}