// Time: O(2^(n+m))
// Space: O(m+n)
// find number of ways to reach from (0,0) to (m-1, n-1) in a mxn grid

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int ways(int row, int col, int m, int n, string s){

    if(row >= m || col >= n){
        return 0;
    }
    
    if(row == m-1 && col == n-1){
        cout<<s<<endl;
        return 1;
    }

    return ways(row, col+1, m, n, s+'R') + ways(row+1, col, m, n, s+'D');
}

int main(){
    int m = 3;
    int n = 3;
    string s;
    int ans = ways(0, 0, m, n, s);
    cout<<"count: "<<ans<<"\n";
}