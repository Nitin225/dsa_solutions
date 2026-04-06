// Time: O(n)
// Space: O(n)
// find first non repeating char;


#include<iostream>
#include<string>
#include<queue>
using namespace std;

void nonRepeatingChar(string s){
    queue<char> Q;
    int freq[26] = {0};

    for(int i=0; i<s.size(); i++){
        Q.push(s[i]);
        freq[s[i]-'a']++;

        while(!Q.empty() && freq[Q.front()-'a'] > 1)
            Q.pop();

    }
    if(Q.empty()) cout<<"-1\n";
    else cout<<Q.front()<<endl;
}

int main(){
    string s = "aabcdbcxd";
    nonRepeatingChar(s);

}