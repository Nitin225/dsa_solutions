// Time: O(n)
// Space: O(1)


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findMin(int V) {
    int ans = 0;
    vector<int> coins = {1 ,2, 5, 10};
    int n = coins.size();
    for(int i = coins.size() - 1; i >= 0 && V > 0; i--){
        if(V >= coins[i]){
            ans += V/coins[i];
            V = n%coins[i];
        }
    }
    return ans;
}

int main(){
    int ans = findMin(34);
    cout<<ans<<endl;
}