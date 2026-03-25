// LeetCode 167
// Time: O(n)
// Space: O(1)
// Approach: Two Pointers (Array must be sorted)

#include <iostream>
#include <vector>
#inlcude <algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int st = 0;
    int end = nums.size() - 1;

    while (st < end) {
        int sum = nums[st] + nums[end];

        if (sum == target)
            return {st + 1, end + 1}; 
        else if (sum > target)
            end--;
        else
            st++;
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15}; // Sorted array
    int target = 9;

    vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        cout << "Indices: " << result[0] << " " << result[1] << endl;
    } else {
        cout << "No solution found" << endl;
    }

    return 0;
}
