#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
        return a[0] < b[0];
    });
    int start = 0;
    int end = intervals[0][1];
    int st = intervals[0][0];
    for(int i=0; i<intervals.size(); i++){
        if(intervals[i][0] <= end){
            end = max(end, intervals[i][1]);
        }
        else {
            ans.push_back({st, end});
            st = intervals[i][0];
            end = intervals[i][1];
        }
    }
    ans.push_back({st, end});
    return ans;
}

int main(){
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = merge(intervals);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i][0]<<" ";
        cout<<ans[i][1]<<endl;;
    }
}