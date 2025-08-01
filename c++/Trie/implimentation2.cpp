#include<bits/stdc++.h>
using namespace std;

// ew means endsWith
// cp means countPrefix
struct Node{
    Node*link[26];
    int ew=0;
    int c=0;
};

class Trie{
    private: 
    Node*root;

    public: 

    Trie(){
        root=new Node();
    }

    // time complexity is O(word.length())
    void insert(string word){
        Node*node=root;
        for(int i=0;i<word.length();i++){
            if(node->link[word[i]-'a']==NULL){
                node->link[word[i]-'a']=new Node();
            }
            node=node->link[word[i]-'a'];
            node->cp=node->cp+1;
        }
        node->ew=node->ew+1;
    }

    // time complexity is O(word.length())
    int countWithStart(string word){
        Node*node=root;

        for(int i=0;i<word.length();i++){
            if(node->link[word[i]-'a']==NULL){
                return 0;
            }
            node=node->link[word[i]-'a'];
        }
        return node->ew;
    }

    // time complexity is O(word.length())
    int countWithPrefix(string word){
        Node*node=root;

        for(int i=0;i<word.length();i++){
            if(node->link[word[i]-'a']==NULL){
                return 0;
            }
            node=node->link[word[i]-'a'];
        }
        return node->cp;
    }

    // in this we are assuming that word is always present 
    // time complexity is O(word.length())
    void erase(string word){
        Node*node=root;

        for(int i=0;i<word.length();i++){
            node=node->link[word[i]-'a'];
            node->cp=node->cp-1;
        }
        node->ew=node->ew-1;
    }
}


int main(){

}

