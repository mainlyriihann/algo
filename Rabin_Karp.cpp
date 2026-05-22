#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> rabinKarp(const string &pattern, const string &text) {
    const int base = 101;
    const int mod = 1e9 + 9;
    int n = pattern.size();
    int m = text.size();
    vector<int> result;
    if (n > m) return result;

    long long hash_pattern = 0, hash_text = 0;
    long long power = 1;

    // Compute base^(n-1)
    for (int i = 0; i < n - 1; ++i)
        power = (power * base) % mod;

    // Compute hash of pattern and first window of text using decreasing powers
    for (int i = 0; i < n; ++i) {
        hash_pattern = (hash_pattern * base + (pattern[i] - 'a' + 1)) % mod;
        hash_text = (hash_text * base + (text[i] - 'a' + 1)) % mod;
    }

    if (hash_text == hash_pattern && text.substr(0, n) == pattern)
        result.push_back(0);

    for (int i = 1; i <= m - n; ++i) {
        // Remove leftmost character
        hash_text = (hash_text - 1LL * (text[i - 1] - 'a' + 1) * power % mod + mod) % mod;
        // Multiply hash by base and add new rightmost character
        hash_text = (hash_text * base + (text[i + n - 1] - 'a' + 1)) % mod;

        if (hash_text == hash_pattern && text.substr(i, n) == pattern)
            result.push_back(i);
    }

    return result;
}

int main() {
    string pattern = "abc";
    string text = "bcabcabc";

    vector<int> positions = rabinKarp(pattern, text);
    for(int i = 0; i < positions.size(); i++) {
        cout << "Pattern found at index: " << positions[i] << endl;
    }

    if (positions.empty()) {
        cout << "Pattern not found" << endl;
    }

    return 0;
}
