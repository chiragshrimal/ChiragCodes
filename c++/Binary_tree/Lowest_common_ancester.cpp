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
 bool find_lca(Node*root,vector<Node*> & temp,Node*target){
    if(root==NULL){
        return false;
    }
    temp.push_back(root);
    if(root==target){
        return true;
    }
    if(find_lca(root->left,temp,target)|| find_lca(root->right,temp,target)){
        return true;
    }
    temp.pop_back();
    return false;
}
// brute force solution 
// find lowest comman ancester 
// time complexity is O(3*n)
// space complexity is O(3*n)
Node*lca(Node*root,Node*p,Node*q){
    vector<Node*> ansp;
    vector<Node*> ansq;
    find_lca(root,ansp,p);
    find_lca(root,ansq,q);
    int n=min(ansp.size(),ansq.size());
    for(int i=0;i<n;i++){
        if(ansp[i]!=ansq[i]){
            return ansp[i-1];
        }
    }
}
// optimal solution 
// time complexity is O(n)
// space complexity is O(n)
Node*ans=NULL;// global variable 
int solve(Node*root,Node*p,Node*q){
    if(root==NULL){
        return 0;
    }
    int left=solve(root->left,p,q);
    int right=solve(root->right,p,q);
    int mid=(root==p|| root==q);
    if(left+mid+right>=2){
        ans=root;
    }
    return left+mid+right>0? 1: 0;// because if wala statement hm ek hi bar chalana chahte haui
}
Node*lca_optimal(Node*root,Node*p,Node*q){
    solve(root,p,q);
    return ans;
}

int main(){
    Node*root=NULL;
    root=build_tree(root);

}