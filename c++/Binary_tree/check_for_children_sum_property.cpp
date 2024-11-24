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
// check for chldren sum property 
// time complexity is O()
// space complexity is O()
pair<bool,int> solve(Node*root){
    if(root==NULL){
        return {true,0};
    }
    if(root->left==NULL && root->right==NULL){
        return {true,root->data};
    }
    pair<bool,int> l=solve(root->left);
    if(l.second==-1){
        return {false,-1};
    }
    pair<bool,int> r=solve(root->right);
    if(root->data==l.second+r.second){
        return {l.first && r.first ,root->data};
    }
    return {false,-1};
    
}
 int isSumProperty(Node *root)
    {
        pair<bool,int> p=solve(root);
        return p.first;
    }

int main(){
    Node*root=NULL;
    root=build_tree(root);
    int ans=isSumProperty(root);
    cout<<ans<<endl;

}