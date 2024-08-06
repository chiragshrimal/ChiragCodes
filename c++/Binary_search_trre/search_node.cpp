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

// insert node into the binary search tree
// time complexity is O(n) ek node ko insert krne ki hai 
// space complexity is O(n) \\ size of the stack  

Node* insert_node(Node*root,int val){
    if(root==NULL){
        root=new Node(val);
        return root;
    }
    if(root->data<val){
        if(root->right==NULL){
            root->right=new Node(val);
            return root;
        }
        insert_node(root->right,val);
    }else{
        if(root->left==NULL){
            root->left=new Node(val);
            return root;
        }
        insert_node(root->left,val);
    }
    return root;

}
void preorder(Node*root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
    return ;
}

// search key 
// time complexity is O(n)
// space complecity is O(n)  
bool search_node(Node*root,int val){
    if(root==NULL){
        return false;
    }
    if(root->data==val){
        return true;
    }
    if(root->data>val){
        return search_node(root->left,val);
    }
    return search_node(root->right,val);

}

int main(){
    Node*root=NULL;
    int n;
    cout<<"enter number of nodes"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cout<<"enter data "<<endl;
        cin>>x;
    root=insert_node(root,x);
    }
    // preorder(root);

    bool check=search_node(root,4);
    cout<<check<<endl;

    

}