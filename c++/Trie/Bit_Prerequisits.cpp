#include<bits/stdc++.h>
using namespace std;

// implimenting tri over here 
struct Node{
    Node*link[2];
    bool flag=false;
};

class Trie{
    private:
    Node*root;

    public:
    Trie(){
        root=new Node();
    }

    void insert(int x){
        Node*node=root;
        for(int i=31;i>=0;i--){
            int bit=(x>>i)&1;
            if(node->link[bit]==NULL){
                node->link[bit]=new Node();
            }
            node=node->link[bit];
        }
        node->flag=true;
    }

    long long int fun(int x){
        Node*node=root;
        long long int ans=0;
        for(int i=31;i>=0;i--){
            int bit=(x>>i)&1;
            if(node->link[1-bit]!=NULL){
                ans= ans|(1LL<<i);
                node=node->link[1-bit];
            }else{
                node=node->link[bit];
            }
        }
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Trie t;
    for(auto it : arr){
        t.insert(it);
    }
    long long int ans=0;
    for(auto it : arr){
        ans=max(ans,t.fun(it));
    }
    cout<<ans<<endl;
    return 0;

}