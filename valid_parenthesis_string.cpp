#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool func(string &s, int idx, int cnt, vector<vector<int>> &dp){
    if(cnt < 0) return 0;
    if(idx == s.size()) return cnt == 0;

    if(dp[idx][cnt] != -1)
        return dp[idx][cnt];

    if(s[idx] == '('){
        dp[idx][cnt] = func(s, idx+1, cnt+1, dp);
        return dp[idx][cnt];
    }

    if(s[idx] == ')'){
        dp[idx][cnt] = func(s, idx+1, cnt-1, dp);
        return dp[idx][cnt];
    }

    dp[idx][cnt]  = func(s, idx+1, cnt+1, dp) || 
                    func(s, idx+1, cnt-1, dp) || 
                    func(s, idx+1, cnt, dp);
                    
    return dp[idx][cnt];
}
bool checkValidString(string s) {
    vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, -1));
    return func(s, 0, 0, dp);
}

int main(){
    string s1 = "(()())";
    string s2 = "(()()))";
    cout<<checkValidString(s1)<<endl;
    cout<<checkValidString(s2)<<endl;
}