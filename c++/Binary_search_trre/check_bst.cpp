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

// check bst 
// time complexity is O()
// space compelxity is O()

bool solve(Node*root,int min ,int max){
    if(root==NULL){
        return true;
    }

    if(min<root->data<max){
        bool p1=solve(root->left,min,root->data);
        if(p1==false){
            return false;
        }
        bool p2=solve(root->right,root->data,max);
        return p1 && p2;
    }else{
        return false;
    }
}

bool checkBst(Node*root){
    int min=INT_MIN;
    int max=INT_MAX;
    return solve(root,min,max);
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

    bool ans=checkBst(root);
    cout<<ans<<endl;
    

}