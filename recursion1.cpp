#include <iostream>
using namespace std;
void f(int x, int y);
int main()
{
    int n;
    cin>> n;
    f(n,0);
}
 
 void f(int i, int sum)
 {
    if(i<1)
    {
        cout<< sum;
        return;
    }
    f(i-1,sum+i);
 }