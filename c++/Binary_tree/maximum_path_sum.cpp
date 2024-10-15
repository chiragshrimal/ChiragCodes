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
// optimal apporach 
int maximum_path_optimal(Node*root,int &maxi){
    if(root==NULL){
        return 0;
    }
    int left=maximum_path_optimal(root->left,maxi);
    int right=maximum_path_optimal(root->right,maxi);

    int temp=max(max(left,right)+root->data,root->data);
    int ans=max(temp,left+right+root->data);
    maxi=max(maxi,ans);
    return temp;
}

int main(){
    Node*root=NULL;
    root=build_tree(root);
    int maxi=INT_MIN;
    int maximum=maximum_path_sum(root,maxi);
    cout<<maximum<<endl;
    int maxi2=INT_MIN;
    maximum_path_optimal(root,maxi2);
    cout<<maxi2<<endl;


}