#include<iostream>
#include<vector>
#include<string>
using namespace std;

void substring(string str, string substr, vector<string>& ans) {
    if(str.size() == 0){
        ans.push_back(substr);
        return;
    }
    char ch = str[0];
    substring(str.substr(1, str.size()-1), substr+ch, ans);
    substring(str.substr(1, str.size()-1), substr, ans);
}


int main(){

    string s = "abc";
    string str = "";
    vector<string> ans;
    substring(s, str, ans);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    
}