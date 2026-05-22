
#include<iostream>
#include<vector>
#include<array>
using namespace std;
int main()
{ int n,d; cin>>n>>d;
    int arr[n];
    d= d%n;
    for(int i=0;i<n;i++ )
    {
        cin>> arr[i];
    } int temp[d]; 
    for(int i=0; i<d;i++)
    {
        temp[i]= arr[i];
    }
    for(int i =0; i<d;i++)
    {cout<< temp[i];}
    cout<< endl;
    
    for(int i = d; i<n;i++ )
    {
        arr[i-d] = arr[i]; 
        
    } 
    for(int i = d-1; i<n;i++)
    {
        arr[i]= temp[i-(d-1)];
   }
    for(int i=0;i<n;i++)
    {
        cout<< arr[i]<< " ";
    }
    cout<< endl;
    

    
}