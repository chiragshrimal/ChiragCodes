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
// sum tree 
// time complexity is O(n)
// space compelxity is o(height)
pair<bool,int> f(Node*root){
    if(root==NULL){
        return pair(true,0);
    }
    if(root->left==NULL && root->right==NULL){
        return pair(true,root->data);
    }
    pair<bool,int> p1=f(root->left);
    pair<bool,int> p2=f(root->right);
    int sum=p1.second+p2.second;
    if(root->data==sum){
        return pair(true && p1.first && p2.first , sum+root->data);
    }else{
        return pair(false,sum+root->data);
    }
} 

int main(){
    Node*root=NULL;
    root=build_tree(root);
    pair<bool,int> p=f(root);
    cout<<p.first<<endl;
}