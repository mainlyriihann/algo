#include<iostream>
using namespace std;
int main()
{
   /*
   longest consecutive sequence: brute
   count = 1
   a[0]= x
   find x+1
   if yes, increase count and change x.
   
   better:
   sort the array
   compare, increase count, store longest.

   greedy:
   use unordered set-> why?
   because findign elemetns in set is O(1).
    */ 
   

   //GREEDY CODE:
   set,
   for( auto it : st)
   {
    if(st.find(it-1)==st.end())
    {
        int cnt =1;
        int x =it;
        while(st.find(x+1) != st.end())
        {
            x=x+1;
            cnt = cnt+1;
        }
        longest = max(longest,cnt);
    }
   }
}