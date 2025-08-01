// 1. generate all the substring 
// 2. whenever i get substring first check if already present or not 
// if already present then dont count otherwise count 


// time cxomplexity is O(n*n)
// generally it is dificult to measuure the space complexity 
// space complexity is O(n*n)
#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* link[26];
    bool flag=false;
};

class Trie{
    private : 
    Node*root;

    public : 
    Trie(){
        root=new Node();
    }

    void insert(string word){
        Node*node=root;
        for(int i=0;i<word.length();i++){
            if(node->link[word[i]-'a']==NULL){
                node->link[word[i]-'a']=new Node();
            }
            node=node->link[word[i]-'a'];
        }
        node->flag=true;
        return;
    }

    bool search(string word){
        Node*node=root;
        for(int i=0;i<word.length();i++){
            if(node->link[word[i]-'a']==NULL){
                return false;
            }
            node=node->link[word[i]-'a'];
        }
        return node->flag;
    }

    int fun(string word){
        int n=word.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            Node*node=root;
            for(int j=i;j<n;j++){
                if(node->link[word[i]-'a']==NULL){
                    node->link[word[i]-'a']=new Node();
                    cnt++;
                }
                node=node->link[word[i]-'a'];
            }
        }
        return cnt+1;
    }

};

int main(){
    string s;
    cin>>s;
    int cnt=0;
    int n=s.size();
    Trie t;
    int ans=t.fun(s);
    cout<<ans<<endl;
    return 0;
}