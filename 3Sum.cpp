// Time: O(n^2)
// Space: O(1)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();
    for(int i=0; i<n; i++){
        int st = i+1;
        int end = n-1;
        if(i > 0 && nums[i] == nums[i-1])
            continue;

        while(st < end){
            int sum = nums[i] + nums[st] + nums[end];
            if(sum == 0) {
                ans.push_back({nums[i], nums[st], nums[end]});
                st++;
                end--;
                while(st<end && nums[st] == nums[st-1])
                    st++;
                while(st<end && nums[end] == nums[end+1])
                    end--;
            }
            else if(sum < 0)
                st++;
            else
                end--;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = threeSum(nums);
    cout<<"[";

    for(int i = 0; i < ans.size(); i++) {
        cout << "[";
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j];
            if(j != ans[i].size() - 1)
                cout << ", ";
        }
        cout << "]";
        if(i != ans.size() - 1)
            cout <<", ";
    }

    cout <<"]"<< endl;
}
