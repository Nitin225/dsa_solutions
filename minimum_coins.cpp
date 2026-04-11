// Time: O(n)
// Space: O(1)


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findMin(int n) {
    int ans = 0;
    vector<int> coins = {1 ,2, 5, 10};
    for(int i = coins.size() - 1; i >= 0 && n > 0; i--){
        if(n >= coins[i]){
            ans += n/coins[i];
            n = n%coins[i];
        }
    }
    return ans;
}

int main(){
    int ans = findMin(34);
    cout<<ans<<endl;
}