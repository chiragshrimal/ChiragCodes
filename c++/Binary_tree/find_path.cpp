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
bool check(Node*root,vector<int> & ans,int target){
    if(root==NULL){
        return false;
    }
    ans.push_back(root->data);
    if(root->data==target){
        return true;
    }
    bool t1=check(root->left,ans,target);
    if(t1==true){
        return true;
    }
    bool t2=check(root->right,ans,target);
    if(t2==true){
        return true;
    }
    ans.pop_back();
    return false;
}
// print path from root to given node 
// time complexity is O()
// sapce complexity is O()
vector<int> find_path(Node*root,int target){
    vector<int> ans;
    check(root,ans,target);
    return ans;
}

int main(){
    Node*root=NULL;
    root=build_tree(root); 
    int target;
    cin>>target;
    vector<int> ans=find_path(root,target);
    for(auto it : ans){
        cout<<it<<" ";
    }

}