#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,q;
    cin >> n >> q;
    vector<long long> nums(n);
    for(int i =0; i< n; i++){
        cin >> nums[i];
    }
    vector<long long> prefsum(n+1, 0);
    for(int i = 1; i<= n; i++){
        prefsum[i] = (prefsum[i-1]+ nums[i-1]);
    }
    for(int i =0; i< q; i++){
        int a,b;
        cin >> a >> b;
        cout << prefsum[b]- prefsum[a-1] << endl;
    }
}