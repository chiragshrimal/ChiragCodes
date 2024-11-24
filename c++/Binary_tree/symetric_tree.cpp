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
bool check(Node*r1,Node*r2){
    if(r1==NULL && r2==NULL){
        return true;
    }
    if(r1==NULL || r2==NULL){
        return false;
    }
    bool t1=check(r1->left,r2->right);
    bool t2=check(r1->right,r2->left);
    if(r1->data==r2->data){
        return true && t1 && t2;
    }
    return false;
}
// symetric tree
// time complexity is O()
// space complexity is O()
bool symetric_tree(Node*root){
    if(root==NULL){
        return true;
    }
    return check(root->left,root->right);
}

int main(){
    Node*root=NULL;
    root=build_tree(root);
    bool t=symetric_tree(root);
    cout<<t<<endl;

}