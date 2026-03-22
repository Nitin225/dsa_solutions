
// Approach: Modified Binary Search
// Time: O(log n)
// Space: O(log n)


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int SearchRotated(vector<int> &nums, int si, int ei, int target){
    if(si > ei) return -1;
    int mid = si + (ei-si)/2;

    if(nums[mid] == target) return mid;

    if(nums[si] <= nums[mid]) {
        if(nums[si] <= target && target <= nums[mid])
            return SearchRotated(nums, si, mid-1, target);
        else
            return SearchRotated(nums, mid+1, ei, target);
    }

    else {
        if(nums[mid] <= target && target <= nums[ei])
            return SearchRotated(nums, mid+1, ei, target);
        else 
            return SearchRotated(nums, si, mid-1, target);
    }
        
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 7;

    int result = SearchRotated(nums, 0, nums.size() - 1, target);

    cout << "Index: " << result << endl;

    return 0;
}