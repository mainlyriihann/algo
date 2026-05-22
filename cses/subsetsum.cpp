/*
Your task is to divide the numbers 1,2,\ldots,n into two sets of equal sum.
Input
The only input line contains an integer n.
Output
Print "YES", if the division is possible, and "NO" otherwise.
After this, if the division is possible, print an example of how to create the sets. First,
 print the number of elements in the first set followed by the elements themselves in a separate
line, and then, print the second set in a similar way.

*/
#include<iostream>
#include<vector>
using namespace std;
using long long = ll;
vector<int> recurse(int ind, int n, int target,){
    vector<int> lis; 
    
    if(target == 0){
        
    }
}
int main(){
    int n ;
    cin>> n;
    ll sum = 1LL*n*(n+1)/2;
    if(sum&1) cout<< "NO";
    else{
        ll target = sum/2;
        vector<int> A ;
         recurse(0,n, target,A);
        vector<int> B(n-A.size());
        
    }
}