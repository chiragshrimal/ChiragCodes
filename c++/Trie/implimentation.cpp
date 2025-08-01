#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *link[26];
    bool flag = false;
    int cnt[26];

    bool containsKey(char ch)
    {
        return (link[ch - 'a'] != NULL);
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
        return;
    }
    Node *get(char ch)
    {
        return link[ch - 'a'];
    }

    bool setEnd(){
        flag=true;
    }

    bool isEnd(){
        return flag;
    }

    int getCnt(char ch){
        return cnt[ch-'a'];
    }
}

class Trie
{

private:
    Node *root;

public:
    Trie()
    {
        // creating object
        root = new Node();
    }

    // time complexity is o(len)
    // space compleixty is o(sizeof(node)*len)
    void insert(string word)
    {

        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!(node->containsKey(word[i])))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);

        }
        node->setEnd();
    }

    bool search(string word){
        Node* node= root;
        for(int i=0;i<word.length();i++){
            if(!(node->containsKey(word[i]))){
                return false;
            }else{
                node=node->get(word[i]);
            }
        }
        return node->isEnd();
    }

    bool startsWith(string word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!(node->containsKey(word[i]))){
                return false;
            }else{
                node=node->get(word[i]);
            }
        }
        return true;
    }

    int count(string word){
        Node*node=root;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(!(node->containsKey(word[i]))){
                return 0;
            }else{
                mini=min(mini,node->getCnt(word[i]));
                node=node->get(word[i]);
            }
        }
        if(node->isEnd()){
            return mini;
        }
        return 0;
    }

    int 


}

int main(){

}
