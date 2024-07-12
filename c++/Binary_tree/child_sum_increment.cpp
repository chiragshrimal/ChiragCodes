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
void preordertraversal(Node*root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preordertraversal(root->left);
    preordertraversal(root->right);
    return ;
}
// child sum increment 
// time complexity is O(n)
// space complexity is O(log(n))
int child_sum_increment(Node*root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }
    int x=0;
    if(root->left){
        x+=root->left->data;
    }
    if(root->right){
        x+=root->right->data;
    }
    if(x>=root->data){
        root->data=x;
    }else{
        if(root->left)
        root->left->data=root->data;
        if(root->right){
            root->right->data=root->data;
        }
    }
    int left=child_sum_increment(root->left);
    int right=child_sum_increment(root->right);
    root->data=left+right;
    return root->data;
}

int main(){
    Node*root=NULL;
    root=build_tree(root);
    child_sum_increment(root);
    preordertraversal(root);
}