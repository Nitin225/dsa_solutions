// Time: O(N^3);
// Space: O(1)


#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        for(int j=i+1; j<n; j++){
            if(j>i+1 && nums[j] == nums[j-1]) continue;
            int k = j + 1;
            int l = n - 1;
            while(k < l){
                long long sum = 1LL * nums[i] + nums[j] + nums[k] + nums[l];
                if(sum == target){
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;
                    while(k<l && nums[k] == nums[k-1]) k++;
                    while(k<l && nums[l] == nums[l+1]) l--;
                } 
                else if(sum < target) 
                    k++;
                else 
                    l--;
            }
        }
    }
    return ans;
}


int main(){
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;

    vector<vector<int>> ans = fourSum(nums, target);
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
