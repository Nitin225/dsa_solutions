#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool endofWord;
    int freq;

    Node(){
        endofWord = false;
    }
};

class Trie {
    Node* root;
public:
    Trie(){
        root = new Node();
        root->freq = -1;
    }

    void insert(string key){
        Node* temp = root;

        for(int i=0; i<key.size(); i++){
            if(temp->children.count(key[i]) == 0){
                temp->children[key[i]] = new Node();
                temp->children[key[i]]->freq = 1;
            } else {
                temp->children[key[i]]->freq++;
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

    string getPrefix(string key){
        Node* temp = root;
        string prefix = "";
        for(int i=0; i<key.size(); i++){
            prefix += key[i];
            if(temp->children[key[i]]->freq == 1){
                return prefix;
            }
            temp = temp->children[key[i]];
        }
        return prefix;
    }
};


void prefix_problem(vector<string> dict){
    Trie trie;
    for(int i=0; i<dict.size(); i++){
        trie.insert(dict[i]);
    }
    for(int i=0; i<dict.size(); i++){
        cout<<trie.getPrefix(dict[i])<<", ";
    }
}

int main(){
    vector<string> dict = {"ramesh", "suresh", "surender", "nikhil"};
    prefix_problem(dict);
    return 0;
}

