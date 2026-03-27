// Time:  O(n)
// Space: O(1)
// Leetcode 31


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int idx1 = -1;
    for(int i=n-2; i>=0; i--){
        if(nums[i] < nums[i+1]){
            idx1 = i;
            break;
        }
    }
    if(idx1 != -1){
        int idx2 = -1;
    for(int j=n-1; j > idx1; j--){
        if(nums[j] > nums[idx1]){
            idx2 = j;
            break;
        }
    }
    swap(nums[idx1], nums[idx2]);
    }
    reverse(nums.begin()+idx1+1, nums.end());

    for(int x : nums){
        cout<<x<<" ";
    }
}

int main(){
    vector<int> nums = {2,1,5};
    nextPermutation(nums);
}