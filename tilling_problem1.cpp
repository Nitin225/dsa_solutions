// time = O(2^n)
// space = O(n)
// Description: count total no of ways tile a floor (2*n) with tile (2*1)

#include <iostream>
using namespace std;

int numTilling(int n) {
    if(n == 0) return 1;
    if(n == 1) return 1;

    return numTilling(n-1) + numTilling(n-2);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int ways = numTilling(n);

    cout << "Total ways: " << ways << endl;

    return 0;
}
