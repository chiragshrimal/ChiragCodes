#include<bits/stdc++.h>
using namespace std;

//  n is the size of the array of strig
// m is the  size of the each string avg
// time complexity is O(nlog(n)+n*m)
// space complexity is O(n*m)

struct Node{
    Node* link[26];
    bool flag=false;
};

class Trie{
    private : 
    Node*root;

    public:

    Trie(){
        root=new Node();
    }
    void insert(string word){
        Node* node=root;

        for(int i=0;i<word.length();i++){
            if(node->link[word[i]-'a']==NULL){
                node->link[word[i]-'a']=new Node();
            }
            node=node->link[word[i]-'a'];
        }
        node->flag=true;
        return ;
    }
    bool allPrefix(string word){
        Node*node=root;
        for(int i=0;i<word.length();i++){
            node=node->link[word[i]-'a'];
            if(node->flag==false){
                return false;
            }
        }
        return true;
    }
};

bool compare(string &s1 , string &s2){
    return s1.size()>=s2.size();
}

int main(){
    int n;
    cin>>n;
    vector<string> arr;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        arr.push_back(str);
    }
    Trie t;
    for(int i=0;i<n;i++){
        t.insert(arr[i]);
    }
    sort(arr.begin(),arr.end(),compare);
    int maxi=0;
    vector<string> ans;
    for(int i=0;i<n;i++){
        if(t.allPrefix(arr[i])){
            if(maxi<=arr[i].size()){
                maxi=arr[i].size();
                ans.push_back(arr[i]);
            }
        }
    }
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}