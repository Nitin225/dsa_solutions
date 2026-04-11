// Time: O(nlog n)
// Space: O(1)
// find longest chain which can be formed from a given set of pairs

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findLongestChain(vector<pair<int, int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](auto &a, auto &b){
            return a.second < b.second;
        });
        int curr = pairs[0].second;
        int currLen = 1;
        for(int i=1; i<pairs.size(); i++){
            if(pairs[i].first > curr){
                currLen++;
                curr = pairs[i].second;
            }
        }
        return currLen;
    }

int main(){
    vector<pair<int,int>> pairs = {{1,2},{2,3},{3,4}};
    cout<<findLongestChain(pairs)<<endl;
}