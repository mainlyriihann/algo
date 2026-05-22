#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> rabinKarp(string pattern, string text){
    int base = 31;
    vector<int> ans;

    int mod =1e9+9;
    int n = pattern.size();
    int m = text.size();
    if(n>m) return ans;
    long long hashpattern =0, hashtext =0; 
    long long power = 1;
    for(int i =0; i<n-1;i++){
        power = (power*base)%mod;
    }
    //computed base^(n-1);
    //computing hashtext and hashpattern
    for(int i=0; i<n;i++){
        hashpattern = (hashpattern*base + (pattern[i]-'a'+1))%mod;
        hashtext = (hashtext*base + (text[i]-'a'+1))%mod;
    }
    if(hashtext == hashpattern && text.substr(0,n) == pattern)
    ans.push_back(0);
    // sliding the window
    for(int i= 1; i<=m-n;i++){
        // remove the last element
        hashtext = (hashtext - ((text[i-1]-'a'+1)*power)%mod +mod)%mod;
        //shift by one
        hashtext = (hashtext*base)%mod;
        hashtext = (hashtext+ (text[i+n-1]-'a'+1))%mod;
        if(hashtext == hashpattern && text.substr(i,n) == pattern)
        ans.push_back(i);
    }
    return ans;
}
int main()
{
    string pattern = "rockstar";
    string text = "pussystarrockstarbackstarrockstarrockker";

    vector<int> positions = rabinKarp(pattern, text);
    for(int i = 0; i < positions.size(); i++) {
        cout << "Pattern found at index: " << positions[i] << endl;
    }

    if (positions.empty()) {
        cout << "Pattern not found" << endl;
    }

    return 0;
}