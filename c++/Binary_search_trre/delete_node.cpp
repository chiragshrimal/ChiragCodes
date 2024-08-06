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
        Node*temp=new Node(val);
        return temp;
    }
    if(root->data<val){
        root->right=insert_node(root->right,val);
    }else{
        root->left=insert_node(root->left,val);
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

// delete a key 
// time compelxity is o()
// space compleoxity is O()

Node*solve(Node*root){
    if(root->left==NULL){
        return root->right;
    }
    if(root->right==NULL){
        return root->left;
    }
    Node*temp=root->left;
    while(temp->right){
        temp=temp->right;
    }
    temp->right=root->right;
    return root->left;
}

Node* delete_node(Node*root,int key){
    if(root==NULL){
        return NULL;
    }

    if(root->data==key){
        return solve(root);
    }
    if(root->data>key){
        root->left=delete_node(root->left,key);
    }else{
        root->right=delete_node(root->right,key);
    }
    return root;
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

    root=delete_node(root,5);
    preorder(root);

}