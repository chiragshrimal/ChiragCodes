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
// height of binary tree
// time complexity is O(n)
// space compelxity is O(log(n))
int height_tree(Node*root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    int h1=height_tree(root->left);
    int h2=height_tree(root->right);
    return max(h1,h2)+1;
}
int main(){
    Node*root=NULL;
    root=build_tree(root);
    int h=height_tree(root);
    cout<<h<<endl;

}