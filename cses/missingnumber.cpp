#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
using ll = long long;
int main(){
    int n ;
    cin>> n;
    vector<ll> arr(n-1);
    for(ll i =0; i< n-1; i++){
       
        cin>> arr[i];
    }
    ll sum =0;
    sum = 1LL*n*(n+1)/2;
    
    ll summ = accumulate(arr.begin(), arr.end(), 0LL);
    
   cout<<  sum - summ;

}