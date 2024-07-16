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
// maximum path sum good concept 
// time complexity is O()
// spac ecomplexity is O()
int maximum_path_sum(Node*root ,int & maxi){
    if(root==NULL){
        return 0;
    }
    int left=max(maximum_path_sum(root->left,maxi),0);
    int right=max(maximum_path_sum(root->right,maxi),0);
    maxi=max(maxi,root->data+left+right);
    return root->data + max(left,right);
}

int main(){
    Node*root=NULL;
    root=build_tree(root);
    int maxi=INT_MIN;
    int maximum=maximum_path_sum(root,maxi);
    cout<<maximum<<endl;

}