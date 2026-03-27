// Time:  O(n! × n)
// Space: O(n! × n)
// Leetcode 46


#include<iostream>
#include<vector>
#include<string>
using namespace std;

void  solve(vector<int>& nums, vector<int> v, vector<vector<int>>& ans){
    if(nums.empty()){
        ans.push_back(v);
        return;
    }

    for(int j=0; j<nums.size(); j++){
            vector<int> nums2 = nums;
            v.push_back(nums[j]);
            nums2.erase(nums2.begin() + j);
            solve(nums2,v,ans);
            v.pop_back();
        }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> v;
    solve(nums, v, ans);
    return ans;
}

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = permute(nums);
    for(auto &row : ans){
    cout << "[ ";
    for(auto x : row) cout << x <<" ";
    cout << "]\n";
    }
}