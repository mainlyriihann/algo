#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (long long k = 1; k <= n; ++k) {
        long long total = k * k * (k * k - 1) / 2;
        long long attacks = 4 * (k - 1) * (k - 2);
        cout << total - attacks << '\n';
    }
    return 0;
}
