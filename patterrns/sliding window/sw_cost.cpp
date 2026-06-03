#include<iostream>
#include<vector>
#include<set>
using namespace std;
using ll = long long;
int k;
multiset<ll> low, high;
ll lowsum = 0 , highsum =0;
void balance(){
    if(low.size() > (k+1)/2){
        high.insert(*low.rbegin());
        lowsum = lowsum - (*low.rbegin());
        highsum += *low.rbegin();
        low.erase(prev(low.end()));
        
        
    }
    if(low.size() < (k+1)/2 && !high.empty()){
        low.insert(*high.begin());
        lowsum += *high.begin();
        highsum -= *high.begin();
        high.erase(high.begin());
        
    }
}
void add(int x){
    if( low.empty() || x <= *low.rbegin()){
        low.insert(x);
        lowsum += x;
    }
    else {
        high.insert(x);
        highsum += x;
    }
    balance();
}
void deleteval(int x){
    auto it = low.find(x);
    if( it != low.end()){
        lowsum -= *it;
        low.erase(it);
    }
    else{
        it = high.find(x);
        if(it != high.end())
        highsum -= *it;
        high.erase(it);
    }
    balance();
}
ll getval(){
    ll median = *low.rbegin();
    ll leftsum = low.size()*median - lowsum;
    ll rightsum = highsum - (median*high.size());
    return leftsum + rightsum;
}
int main(){
    int n;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i =0; i< n; i++){
        cin >> nums[i];
    }
    vector<int> ans;
    
    for(int r =0; r< n; r++){
        int min_cost = 0;
        int num = nums[r];
        add(num);
        if(r >= k){
            deleteval(nums[r-k]);
        }
        if(r>= k-1){
            cout << getval() << " ";
        }
        
        
    }
   
}