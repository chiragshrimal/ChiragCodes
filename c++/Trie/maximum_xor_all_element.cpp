#include<bits/stdc++.h>
using namespace std;

// time complexity is o(q)
// space complexity is o(2*n)

struct Node{
    Node*link[2];
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
        return ;
    }

    int fun(int x){
        Node*node=root;
        long long int ans=0;
        for(int i=31;i>=0;i--){
            int bit=(x>>i)&1;
            if(node->link[1-bit]==NULL){
                node=node->link[bit];
            }else{
                ans=ans|(1LL<<i);
                node=node->link[1-bit];
            }
        }
        return ans;
    }

    
};

bool compare(pair<int,pair<int,int>>&p1, pair<int,<int,int>>&p2){
    return p1.second.first<=p2.second.first;
}

int main(){
    int n,q;
    cin>>n>>q;
    vector<int> arr(n,0);
    vector<pair<int,int>> quries(q,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<q;i++){
        int x,m;
        cin>>x>>m;
        quries.push_back({x,m});
    }
    sort(arr.begin(),arr.end());

    vector<pair<int,pair<int,int>>> temp;
    for(int i=0;i<q;i++){
        int f=quries[i].first;
        int s=quries[i].second;
        temp.push_back({f,{s,i}});
    } 
    sort(temp.begin(),temp.end(),compare);
    vector<int> ans(q,0);

    Trie t;
    int i=0;
    for(auto it : temp){
        while(i<n && arr[i]<=it.second.first){
            t.insert(arr[i]);
            i++;
        }
        if(i==0){
            ans[it.second.second]=-1;
        }else{
            ans[it.second.second]=t.fun(x);
        }
    }

    return 0;
}