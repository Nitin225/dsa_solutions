// Time: O(3n);
// Space: O(2n);

#include<iostream>
#include<vector>
using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> left(n, 0), right(n, 0);

    left[0] = 1;
    right[n-1] = 1;

    for(int i=1; i<n; i++){
        if(ratings[i] > ratings[i-1]) 
            left[i] = left[i-1] + 1;
        else 
            left[i] = 1;

        if(ratings[n-i-1] > ratings[n-i]) 
            right[n-i-1] = right[n-i] + 1;
        else 
            right[n-i-1] = 1;
    }

    int sum = 0;
    for(int i=0; i<n; i++){
        sum += max(left[i], right[i]);
    }
    return sum;
}

int main(){
    vector<int> v = {1,3,5,2,6,2,1,1,1,3,4,2};
    cout<<candy(v)<<endl;
}