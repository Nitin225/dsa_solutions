// Problem: Count Good Numbers
// Approach: Fast Exponentiation (recursive)
// Time Complexity: O(log n)
// Space Complexity: O(log n)

class Solution {
private:
    long long mod = 1e9 + 7;

    long long power(long long n, long long p) {
        if (p == 0) return 1;

        long long half = power(n, p / 2);

        if (p % 2 == 0)
            return (half * half) % mod;
        else
            return ((half * half) % mod * n) % mod;
    }

public:
    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;  // positions with 5 choices
        long long odd  = n / 2;        // positions with 4 choices

        long long ans = (power(5, even) * power(4, odd)) % mod;

        return ans;
    }
};