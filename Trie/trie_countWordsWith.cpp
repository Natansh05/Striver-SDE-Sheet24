#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* links[26];
    int end_c;
    int pre_c;

    Node(){
        end_c = 0;
        pre_c = 0;
    }

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    void put(char ch,Node* node){
        links[ch-'a'] = node;
        return;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void increase_prefixCount(){
        pre_c++;
    }
    void decrease_prefixCount(){
        pre_c--;
    }
    int getPrefixCount(){
        return pre_c;
    }

    void increase_endingCount(){
        end_c++;
    }
    void decrease_endingCount(){
        end_c--;
    }
    int getEndingCount(){
        return end_c;
    }


};


class Trie{

    public:
    Node* root;
    Trie(){
        root = new Node();
        //  on creation of a new object , new trie gets created for it 
    }

    void insert(string word){
        // O(len)
        Node* node = root;
        int n = word.size();
        for(int i=0;i<n;++i){
            if(!node->containsKey(word[i]))
                    node->put(word[i],new Node());
            node = node->get(word[i]);
            node->increase_prefixCount();
        }
        node->increase_endingCount();
    }

    int countWordsEqualTo(string word){
        // O(len)
        Node* node = root;
        int n = word.size();
        for(int i=0;i<n;++i){
            if(!node->containsKey(word[i]))
                return 0;
            node = node->get(word[i]);
        }
        return node->getEndingCount();
    }

    int countWordsStartingWith(string word){
        // O(len)
        Node* node = root;
        int n = word.size();
        for(int i=0;i<n;++i){
            if(!node->containsKey(word[i]))
                return 0;
            node = node->get(word[i]);
        }
        return node->getPrefixCount();
    }

    void erase(string word){
        // O(len)
        Node* node = root;
        int n = word.size();
        for(int i=0;i<n;++i){
            if(!node->containsKey(word[i]))
                return;
            node = node->get(word[i]);
            node->decrease_prefixCount();
        }
        node->decrease_endingCount();
        cout<<"Word :"<<word<<" is erased :) "<<endl;
        return;
    }
};


int main(){
    Trie* obj = new Trie();
    obj->insert("apple");
    obj->insert("app");
    obj->insert("don");
    obj->insert("dad");

    int eq = obj->countWordsEqualTo("api");
    int st = obj->countWordsStartingWith("d");
    cout<<eq<<endl;
    cout<<st<<endl;
    obj->erase("apple");
    int eq2 = obj->countWordsEqualTo("apple");
    cout<<eq2<<endl;
    cout<<"main Function is called"<<endl;
    return 0;
}
