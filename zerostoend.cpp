#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int n; 
    cin>> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>> a[i];
    }
   int j=-1;
   for(int i=0;i<n;i++)
   {
    if(a[i] == 0)
    { j = i;
    break;}
   }
   
   for(int i = j+1; i<n ;i++)
   {
    if(a[i] != 0)
    {
        swap(a[i],a[j]);
        j++;
    }
    
   }
   for(int i=0;i<n;i++)
    {
        cout<< a[i]<<" ";
    }
   
} 