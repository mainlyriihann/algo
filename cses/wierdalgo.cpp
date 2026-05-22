#include<iostream>
#include<vector> 
using namespace std;
using ll = long long;
int main(){
    ll n;
    cin>> n;
    vector<ll> ans;
    ans.push_back(n);
    while(n!=1){
        if(n&1){ n = ((n*3)+1)*1LL;
        ans.push_back(n);}
        else {
            n = n/2;
            ans.push_back(n);
        }
    }
    for(ll i =0; i< ans.size(); i++){
        cout<< ans[i] << " ";
    }
}