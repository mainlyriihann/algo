#include <iostream>
#include <vector>
#include <array>
using namespace std;
void sssort(int arr[], int y)
{ 
    for(int i =0; i<= y-2;i++)
    {
        for(int j=0; j<= y-2-i;j++)
        {
            if( arr[j]> arr[j+1])
            { int temp =arr[j+1];
            arr[j+1]= arr[j];
            arr[j]= temp;
            }
        }
    }
}

int main()
{
 int n;
 cin >> n;
 int arr[n];
 for(int i= 0; i<n;i++)
 {
    cin >> arr[i];
 }    
 sssort(arr, n);
 
 for(int i=0;i<n;i++)
 {
    cout<< arr[i]<< ' ' ;
 }
}
