
/*
    Matrix Chain Multiplication (MCM)

    Time Complexity:
    1. Recursion    : Exponential
    2. Memoization  : O(N^3)
    3. Tabulation   : O(N^3)

    Space Complexity:
    1. Recursion    : O(N) recursion stack
    2. Memoization  : O(N^2) + O(N) stack
    3. Tabulation   : O(N^2)

    Example:
    arr = {1, 2, 3, 4, 3}

    Matrices:
    A1 = 1 x 2
    A2 = 2 x 3
    A3 = 3 x 4
    A4 = 4 x 3

    Output: 30
*/

#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

// Recursion

int mcmRec(vector<int>& arr, int i, int j) {
    if(i == j)
        return 0;
    
    int ans = INT_MAX;

    for(int k=i; k<j; k++){
        int cost1 = mcmRec(arr, i, k);
        int cost2 = mcmRec(arr, k+1, j);
        // curr partition cost
        int currCost = cost1 + cost2 + arr[i-1]*arr[k]*arr[j];
        ans = min(ans, currCost);
    }
    return ans;
}

// Memoization

int mcmMem(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {

    if(i == j)
        return 0;
    
    int ans = INT_MAX;
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    for(int k=i; k<j; k++){
        int cost1 = mcmMem(arr, i, k, dp);
        int cost2 = mcmMem(arr, k+1, j, dp);
        // curr partition cost
        int currCost = cost1 + cost2 + arr[i-1]*arr[k]*arr[j];
        ans = min(ans, currCost);
    }
    return dp[i][j] = ans;
}

// Tabulation

int mcmDP(vector<int>& arr) {

    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i=0; i<n; i++){
        dp[i][i] = 0;
    }

    for(int len=2; len<n; len++){
        for(int i=1; i<=n-len; i++){
            int j = i+len-1;
            dp[i][j] = INT_MAX;
            for(int k=i; k<j; k++){
                int cost1 = dp[i][k];
                int cost2 = dp[k+1][j];
                int currCost = cost1 + cost2 + arr[i-1]*arr[k]*arr[j];
                dp[i][j] = min(dp[i][j], currCost);
            }
        }
    }
    return dp[1][n-1];
};


int main() {

    vector<int> arr = {1, 2, 3, 4, 3};
    int n = arr.size();

    cout << "Recursion: "<< mcmRec(arr, 1, n - 1)<< endl;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << "Memoization: "<< mcmMem(arr, 1, n - 1, dp)<< endl;
    cout << "Tabulation: "<< mcmDP(arr)<< endl;

    return 0;
}

