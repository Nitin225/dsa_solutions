// Binary Exponentiation (Iterative)
// Time: O(log n)
// Space: O(1)

#include <iostream>
using namespace std;

long long mod = 1e9 + 7;

long long powerIterative(long long n, long long p) {
    long long res = 1;

    while (p > 0) {
        if (p & 1) res = (res * n) % mod;
        n = (n * n) % mod;
        p >>= 1;
    }

    return res;
}

int main() {
    long long n = 4, p = 13;
    cout << powerIterative(n, p) << endl;
}