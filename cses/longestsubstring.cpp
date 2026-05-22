/*
You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest 
repetition in the sequence. This is a maximum-length substring containing only one type of character.
Input--> 
The only input line contains a string of n characters.
*/
#include<iostream>
#include<vector>
#include<string>
#include <climits>
using namespace std;
using ll = long long;
int main(){

    string input;
    cin >> input;
     ll left = 0;
   
     ll maxi = INT_MIN;
     ll cnt = 0;
     // use size_t for unsigned -> return type of .size(), .length();
     for(size_t right =0; right<input.length(); right++){
        if(input[left] == input[right]){
            cnt++;
        }
        else{
            left = right;
            cnt = 1;
        }
        maxi = max(maxi,cnt);
     }
              
     cout<< maxi;
}
