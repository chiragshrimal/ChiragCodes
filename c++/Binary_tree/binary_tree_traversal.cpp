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
    cout<<"enter left child"<<endl;   
    root->left=build_tree(root->left);
    cout<<"enter right child"<<endl;
    root->right=build_tree(root->right);
    return root;
}
// preorder traversal
// time complexity is O()
// space complexity is O(1)
void preordertraversal(Node*root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preordertraversal(root->left);
    preordertraversal(root->right);
    return ;
}
// post order traversal
// time complexity is O()
// space complexity is O()
void postordertraversal(Node*root){
    if(root==NULL){
        return ;
    }
    postordertraversal(root->left);
    postordertraversal(root->right);
    cout<<root->data<<" ";
    return ;
}
// inorder traversal 
// time complexity is o()
// space complexity is o()
void inordertraversal(Node*root){
    if(root==NULL){
        return ;
    }
    inordertraversal(root->left);
    cout<<root->data<<" ";
    inordertraversal(root->right);
    return ;
}
// level order traversal 
// time complexity is O()
// space complexity is O(n)// n is number of nodes
void levelordertraversal(Node*root){
    queue<Node*> q;
    if(root!=NULL){
        q.push(root);
    }
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return ;
}
int main(){
    Node*root=NULL;
    root=build_tree(root);
    preordertraversal(root);
    cout<<endl;
    postordertraversal(root);
    cout<<endl;
    inordertraversal(root);
    cout<<endl;
    levelordertraversal(root);
}
// 5
// 4
// 3
// -1
// -1
// 6
// -1
// -1
// 2
// -1
// -1

