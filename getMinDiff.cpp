// Time Complexity : O(N * W) 
// Space Complexity : O(N * W)

#include<iostream>
#include<vector>
using namespace std;

int getMinDiff(vector<int> nums){
    int totSum = 0;
    for(int x: nums){
        totSum += x;
    }

    int n = nums.size();
    int w = totSum/2;
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));

    for(int i=1; i<n+1; i++){
        for(int j=1; j<w+1; j++){
            if(nums[i-1] <= j){
                dp[i][j] =  max(nums[i-1] + dp[i-1][j-nums[i-1]], dp[i-1][j]);           
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return abs(totSum - 2*dp[n][w]);
}

int main() { 
    vector<int> nums = {1, 6, 11, 5}; 
    cout << "Minimum Difference = " << getMinDiff(nums) << endl; 
    return 0; 
}