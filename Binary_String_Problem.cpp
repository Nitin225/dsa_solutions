// time: O(2^n)
// space: O(n)
// Description: Print all binary string of size N without any consecutive 1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void BinaryString(int n, string s1, int last, vector<string>& s) {
  if(n == 0) {
    s.push_back(s1);
    return;
  }
  BinaryString(n-1, s1+'0', 0, s);
  if(last != 1)
    BinaryString(n-1, s1+'1', 1, s);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<string> result;

    BinaryString(n, "", 0, result);

    cout << "Binary strings without consecutive 1:\n";
    for(auto &str : result) {
        cout << str << endl;
    }

    return 0;
}
