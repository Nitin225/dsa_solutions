
// Time: O(2^n)
// Space: O(n) recursion stack
// Auxiliary Space (including output): O(2^n * n)
// Leetcode 90 - Subsets II

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void solve(vector<int>& nums, vector<int>& subarr, int index, vector<vector<int>>& ans){
    ans.push_back(subarr);

    for(int i = index; i < nums.size(); i++){

        // skip duplicates
        if(i > index && nums[i] == nums[i-1]) continue;

        subarr.push_back(nums[i]);
        solve(nums, subarr, i+1, ans);
        subarr.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> subarr = {};
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    solve(nums, subarr, 0, ans);
    return ans;
}

int main(){

    vector<int> nums = {1,2,3,2};
    vector<vector<int>> v = subsets(nums);
    for(auto &row : v){
    cout << "[ ";
    for(auto x : row) cout << x <<" ";
    cout << "]\n";
}
}
