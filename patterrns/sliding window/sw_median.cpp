#include<iostream>
#include<vector> 
#include<set>
using namespace std;
using ll = long long;
int k;
multiset<ll> low, high;
void balance(){
    while(low.size() > (k+1)/2){
        high.insert(*low.rbegin());
        low.erase(prev(low.end()));
    }
    while(low.size() < (k+1)/2 && !high.empty()){
        low.insert(*high.begin());
        high.erase(high.begin());
    }
}
void add(int x){
    if(low.empty() || x <= *low.rbegin()){
        low.insert(x);
    }
    else high.insert(x);
    balance();
}
void deleteval(int x){
    auto it = low.find(x);
    if( it != low.end()){
        low.erase(it);
    }
    
    else{
        it = high.find(x);
        if( it != high.end())
        high.erase(it);
    }
    balance();
}
int main(){
   int n;
   cin >> n >> k;
   vector<int> nums(n);
   for(int i =0; i< n; i++) cin >> nums[i];
   for(int r =0; r< n; r++){
    add(nums[r]);
    if(r >= k){
        deleteval(nums[r-k]);
    }
    if(r >= k-1){
        cout << *low.rbegin() << " ";
    }
   }
   return 0;
        }
    