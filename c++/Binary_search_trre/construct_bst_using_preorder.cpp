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

// given preorder constructor bst 
// brute force we have done in all bst code 
// time complexity is O(n*n)
// space commplexity is O(1)



// better apporach 
// using concept of given preorder then find postorder and make unique bst
// time complexity is O(nlog(n))
// space complexity is O(n)



// optimal apporach 
// using concept of bst
// time complexity is O(3*n)
// space complexity is O(1)

// concept hai ki i is always increases so we have pass by refrence 
Node*solve(vector<int>& v,int i ,int bound){
    if(i==v.size()|| v[i]>bound){
        return NULL;
    }
    Node*root=new Node(v[i++]);
    root->left=solve(v,i,v[i]);
    root->right=solve(v,i,bound);
    return root;
}

Node*bst(vector<int>& v){
    int i=0;
    return solve(v,i,INT_MAX);
}

int main(){
    Node*root=NULL;
    int n;
    cout<<"enter number of nodes"<<endl;
    cin>>n;

}