#include<bits/stdc++.h>
using namespace std;

class Node{
    public :
    Node*left;
    int data;
    Node*right;
    Node(int val){
        left=NULL;
        right=NULL;
        data=val;
    }
};
Node*build_tree(Node*root){
    cout<<"enter data"<<endl;
    int val;
    cin>>val;
    // stopping criteria;
    if(val==-1){
        return NULL;
    }
    root=new Node(val);
    root->left=build_tree(root->left);
    root->right=build_tree(root->right);
    return root;
}
// right side view of tree
// time complexity is O()
// space complexiyt is O()
vector<int> right_view(Node*root){
    map<int,int> m;
    queue<pair<int,Node*>> q;
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    q.push(pair(0,root));
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        m[it.first]=it.second->data;
        if(it.second->left!=NULL){
            q.push(pair(it.first+1,it.second->left));
        }

        if(it.second->right){
            q.push(pair(it.first+1,it.second->right));
        }
    }
    for(auto it : m){
        ans.push_back(it.second);
    }
    return ans;

}

int main(){
    Node*root=NULL;
    root=build_tree(root);
    vector<int> ans=right_view(root);
    for(auto it : ans){
        cout<<it<<" ";
    }
}