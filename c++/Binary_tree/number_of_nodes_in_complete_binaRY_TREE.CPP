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
int left_height(Node*temp){
    int height=0;
    while(temp){
        height++;
        temp=temp->left;
    }
    return height;
}
int right_height(Node*temp){
    int height=0;
    while(temp){
        height++;
        temp=temp->right;
    }
    return height;

}
// number of nodes in complete binary tree
// space complexity is O()
// time complexity is O()
int nodes_in_complete_binary(Node*root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    int left=left_height(root);
    int right=right_height(root);
    if(left==right){
        return 1<<left -1;
    }
    int leftpart=nodes_in_complete_binary(root-left);
    int rightpart=nodes_in_complete_binary(root->right);
    return 1+leftpart + rightpart;
}

int main(){
    Node*root=NULL;
    root=build_tree(root);

}