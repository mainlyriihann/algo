#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    int n;
    cin>> n; 
    bool flag = true;
    if(n == 2 || n == 3){  
        flag = false;
        cout<< "NO SOLUTION";}
    vector<int> ans;
    if(n == 4) {cout<< "2 4 1 3"; return 0;}
    for(ll i =1; i<= n; i++) 
    if(i&1) ans.push_back(i);

    for(ll i =1; i<= n; i++) 
    if(!(i&1)) ans.push_back(i);
        if(flag){
        for(ll i =0; i< n; i++) 
        cout<< ans[i] << " ";      
        }
}