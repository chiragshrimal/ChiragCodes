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

// ceil of the  key 
// time complexity is O(n)
// space complecity is O(n)  
int  find(Node*root,int val,int pre){
    if(root==NULL){
        return pre;
    }
    if(root->data==val){
        return val;
    }
    if(root->data>val){
        pre=root->data;
        return find(root->left,val,pre);
    }
    return find(root->right,val,pre);

}
int ceil(Node*root,int val){
    int pre=-1;
    return find(root,val,pre);
}

int calculate_floor(Node*root,int val,int pre){
     if(root==NULL){
        return pre;
    }
    if(root->data==val){
        return val;
    }
    if(root->data>val){
        return calculate_floor(root->left,val,pre);
    }
    pre=root->data;
    return calculate_floor(root->right,val,pre);
}

int floor(Node*root,int val){
    int pre=-1;
    return calculate_floor(root,val,pre);
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

    // int ceil_val=ceil(root,10);
    // cout<<ceil_val<<endl;

     int floor_val=floor(root,10);
    cout<<floor_val<<endl;

    

}