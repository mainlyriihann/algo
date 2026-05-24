#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i =0; i< n; i++){
        cin>> arr[i];
    }
    int c =0;
    for(int i = n-2; i >= 1;i--){
        int curr = arr[i];
        int prev = arr[i+1];
        int forward = arr[i-1];
        if(curr == 0){
            int tmp = prev - 1;
            if(abs(tmp-forward) <= 1 && abs(tmp-forward) >= -1) c++;
            int tmp1 = prev;
            if(abs(tmp1-forward) <= 1 && abs(tmp1-forward) >= -1) c++;
            int tmp2 = prev+1;
            if(abs(tmp2-forward) <= 1 && abs(tmp2-forward) >= -1) c++;
        }
    }
    
}