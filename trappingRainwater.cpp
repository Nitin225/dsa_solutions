// Time: O(3n);
// Space: O(2n)

#include<iostream>
#include<vector>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();

    vector<int> prefix(n,0);
    vector<int> suffix(n,0);

    prefix[0] = height[0];
    for(int i=1; i<n; i++){
        prefix[i] = max(prefix[i-1], height[i]);
    }

    suffix[n-1] = height[n-1];
    for(int i=1; i<n; i++){
        suffix[n-i-1] = max(suffix[n-i], height[n-i-1]);
    }
    
    int total = 0;
    for(int i=1; i<n-1; i++){
        total += min(prefix[i], suffix[i]) - height[i];
    }
    return total;
}

int main(){
    vector<int> height = {2, 1, 0, 5, 3};
    int ans = trap(height);
    cout<<"Water Trapped: "<<ans<<endl;
}

