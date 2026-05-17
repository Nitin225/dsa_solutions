#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using  namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool endofWord;

    Node(){
        endofWord = false;
    }
};

class Trie {
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insert(string key){
        Node* temp = root;

        for(int i=0; i<key.size(); i++){
            if(temp->children.count(key[i]) == 0){
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }
        temp->endofWord = true;
    }

    bool search(string key){
        Node* temp = root;

        for(int i=0; i<key.size(); i++){
            if(temp->children.count(key[i])){
                temp = temp->children[key[i]];
            } else {
                return false;
            }
        }
        return temp->endofWord;
    }
};

bool helper(Trie &trie, string key, unordered_map<string,bool>& dp){
    if(key.size() == 0){
        return true;
    }

    if(dp.count(key)){
    return dp[key];
    }

    for(int i=0; i<key.size(); i++){
        string first = key.substr(0, i+1);
        string second = key.substr(i+1);

        if(trie.search(first) && helper(trie, second, dp)) {
            return dp[key] = true;;
        }
    }
    return dp[key] = false;
}

bool WordBreak(vector<string> dict, string key){
    Trie trie;
    unordered_map<string,bool> dp;
    for(int i=0; i<dict.size(); i++){
        trie.insert(dict[i]);
    }
    return helper(trie, key, dp);
}

int main(){
    vector<string> dict = {"the", "there", "their", "thee", "a", "any"};
    string key = "thereany";
    cout << WordBreak(dict, key);
}