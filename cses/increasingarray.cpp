#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    int n;
    cin>> n;
    vector<ll> arr(n);
    for(ll i =0; i< n; i++) cin>> arr[i];
    ll cnt = 0;
    for(ll i =0; i< n-1; i++){
        if(arr[i] < arr[i+1]) continue;
        else{
            cnt = (cnt + 1LL*(arr[i] - arr[i+1]));
            arr[i+1] = arr[i];
        }
    }
        cout<< cnt;
}