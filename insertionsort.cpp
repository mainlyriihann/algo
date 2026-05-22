#include<iostream>
#include<array>
using  namespace std;


void iswap(int arr[],int x)
{
  for(int i= 0;i <x; i--)
  { int j =i;
   while(j>0 && arr[j-1]> arr[j])
   {
    int temp = arr[j-1];
    arr[j-1]= arr[j];
    arr[j] = temp;
   }
   j--;
  }
}
int main()
{
    int n; cin>> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    iswap(arr, n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<< ' ';
    }

}