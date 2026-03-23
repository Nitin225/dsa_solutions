// Binary Exponentiation (Recursive)
// Time: O(log n)
// Space: O(log n)

#include <iostream>
using namespace std;

long long mod = 1e9 + 7;

long long powerRecursive(long long n, long long p) {
    if (p == 0) return 1;

    long long half = powerRecursive(n, p / 2);

    if (p % 2 == 0)
        return (half * half) % mod;
    else
        return ((half * half) % mod * n) % mod;
}

int main() {
    long long n = 3, p = 13;
    cout << powerRecursive(n, p) << endl;
}