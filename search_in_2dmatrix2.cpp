// Time: O(m + n)
// Space: O(1)
// staircase approach

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool searchMatrixStaircase(vector<vector<int>>& mat, int key) {
    int m = mat.size();
    int n = mat[0].size();

    int i = 0, j = n - 1; // start from top-right

    while (i < m && j >= 0) {
        if (mat[i][j] == key)
            return true;
        else if (mat[i][j] > key)
            j--;
        else
            i++;
    }
    return false;
}


int main() {
    vector<vector<int>> mat = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int key = 16;
    // Staircase Search
    if (searchMatrixStaircase(mat, key))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}