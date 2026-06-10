// Brute Force
// Time: O(N^4logN);
// Space: O(1)


#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;



vector<vector<int>> fourSum(vector<int>& nums, int target) {
    set<vector<int>> ans;
    int n = nums.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                for(int l=k+1; l<n; l++){
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target){
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        ans.insert(temp);
                    } 
                }
            }
        }
    }
    return vector<vector<int>>(ans.begin(), ans.end());
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
