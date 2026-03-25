// Time: O(m * log n)
// Space: O(1)
// Binary Search Row-wise

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool searchMatrixBinary(vector<vector<int>>& mat, int key) {
    for (int i = 0; i < mat.size(); i++) {
        if (binary_search(mat[i].begin(), mat[i].end(), key))
            return true;
    }
    return false;
}

int main(){
    vector<vector<int>> mat = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int key = 16;

    if (searchMatrixBinary(mat, key))
        cout << "Found";
    else
        cout << "Not Found";
}

