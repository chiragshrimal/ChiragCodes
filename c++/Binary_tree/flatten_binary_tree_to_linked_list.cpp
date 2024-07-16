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
Node*ADD_list(Node*root,Node*left,Node*right){
    root->left=NULL;
    if(left==NULL){
        root->right=right;
        return root;
    }
    if(right==NULL){
        root->right=left;
        return root;
    }
    Node*temp=left;
    while(temp->right!=NULL){
        temp=temp->right;
        temp->left=NULL;
    }
    temp->right=right;
    root->right=left;
    return root;
}
// flatten binary tree to linked list 
// time complexity is O()
// space complexity is O()
Node* flatten_binary_tree(Node*root){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        return root;
    }
    Node*left=flatten_binary_tree(root->left);
    Node*right=flatten_binary_tree(root->right);
    return ADD_list(root,left,right);
}
// optimal apporach 
// time complexity is O(n)
// space complexity is O(1)
void flatten_optimal(Node*root){
    if(root==NULL){
        return ;
    }
    Node*cur=root;
    while(cur!=NULL){
        if(cur->left==NULL){
            cur=cur->right;
        }else{
            Node*temp=cur->left;
            while(temp->right!=NULL){
                temp=temp->right;
            }
            temp->right=cur->right;
            cur->right=cur->left;
            cur->left=NULL;
        }
    }
}
int main(){
    Node*root=NULL;
    root=build_tree(root);

}