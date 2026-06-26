#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    int n,q;
    cin >> n >> q;
    vector<ll> nums(n);
    for(int i = 0; i<n; i++){
        cin >> nums[i];
    }
    for(int i = 1; i < n; i++){
        nums[i] = min(nums[i], nums[i-1]);
    }
    for(int i = 0;i < q; i++){
        int a,b;
        cin >> a >> b;
        cout << min(nums[b-1],nums[a-1]) << endl;
    }
}