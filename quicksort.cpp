#include <iostream>
#include<vector>
using namespace std;

 int f(vector<int> &arr,int low,int high)
 {
    int i=0; int j= high;
    while(i<j)
    {
       while(arr[i]<= arr[0]&& i<=high)
       {i++;}
       while(arr[j]> arr[0]&& j>=low)
      {j--;}
      if(i<j)
      {
        int temp = arr[i];
        arr[i]= arr[j];
        arr[j]= temp;
      }

    }
 }
void qs( vector<int> &arr,int low,int high)
{ 
    if(low<high)
{    int p_index = f(arr, low,high);
    qs(arr,low, p_index-1);
    qs(arr,p_index+1,high);
}
}
int main()
{ vector<int> arr;
    int n;
    cin>> n;
    for(int i=0;i<n;i++)
    {
        cin>> arr[i];
    }
    qs(arr,0,n-1);
    for(int i=0;i<n;i++)
    { cout<< arr[i];}
}