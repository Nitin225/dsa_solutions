
// Time: O(2^n)
// Space: O(n) recursion stack
// Leetcode 78 - Subsets

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void solve(vector<int>& nums, vector<int>& subarr, int index, vector<vector<int>>& ans){
    if(index >= nums.size()){
        ans.push_back(subarr);
        return;
    }

    solve(nums, subarr, index+1, ans);

    subarr.push_back(nums[index]);
    solve(nums, subarr, index+1, ans); 

    subarr.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> subarr = {};
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    solve(nums, subarr, 0, ans);
    return ans;
}

int main(){

    vector<int> nums = {1,2,3};
    vector<vector<int>> v = subsets(nums);
    for(auto &row : v){
    cout << "[ ";
    for(auto x : row) cout << x <<" ";
    cout << "]\n";
}
}
