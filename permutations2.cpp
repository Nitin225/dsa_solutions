// Time:  O(n! × n) or O(n! × n log n)
// Space: O(n! × n)
// Leetcode 47
// duplicate elements anre allowed


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

void  solve(vector<int>& nums, vector<int> v, vector<vector<int>>& ans){
    if(nums.empty()){
        ans.push_back(v);
        return;
    }

    set<int> used;
    for(int j=0; j<nums.size(); j++){
        if(used.count(nums[j])) continue;  // skip same value at this level
        used.insert(nums[j]);

        vector<int> nums2 = nums;
        v.push_back(nums[j]);
        nums2.erase(nums2.begin() + j);
        solve(nums2, v, ans);
        v.pop_back();
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    // sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> v;
    solve(nums, v, ans);
    return ans;
}

int main(){
    vector<int> nums = {1,1,3};
    vector<vector<int>> ans = permute(nums);
    for(auto &row : ans){
    cout << "[ ";
    for(auto x : row) cout << x <<" ";
    cout << "]\n";
    }
}