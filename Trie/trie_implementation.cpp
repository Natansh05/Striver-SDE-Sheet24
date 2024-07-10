// link - https://leetcode.com/problems/implement-trie-prefix-tree/description/


#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* links[26];
    bool flag = 0;

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = 1;
        return;
    }

    bool isEnd(){
        return flag;
    }
};


class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        // O(len)
        Node* node = root;
        int n = word.size();
        for(int i=0;i<n;++i){
            if(!node->containsKey(word[i]))
                node->put(word[i],new Node());
            node = node->get(word[i]);
        }

        node->setEnd();
    }
    
    bool search(string word) {
        // O(len)
        Node* node = root;
        int n = word.size();
        for(int i=0;i<n;++i){
            if(!node->containsKey(word[i]))
                return 0;
            node = node->get(word[i]);
        }

        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        // O(len)
        int m = prefix.size();
        Node* node = root;
        for(int i=0;i<m;++i){
            if(!node->containsKey(prefix[i]))
                return 0;
            node = node->get(prefix[i]);
        }
        return 1;
    }
};


int main(){
    cout<<"Main function called"<<endl;
    Trie* obj = new Trie();
    obj->insert("apple");
    obj->insert("app");
    obj->insert("don");
    obj->insert("dad");
    bool param_2 = obj->search("apple");
    cout<<param_2<<endl;
    bool param_3 = obj->startsWith("da");
    cout<<param_3<<endl;
    return 0;
}
