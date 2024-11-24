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
// maximum width of binary tree
// overflow hoga isme 
// time complexity is O()
// space complexity is O()
int maximum_width(Node*root){
   queue<pair<Node*,long long int>> q;
    long long int ans=0;
    q.push({root,0});
    while(!q.empty()){
        int size=q.size();
        long long int mini=q.front().second;
        long long int first,last;
        for(int i=0;i<size;i++){
            long long int cur_id=q.front().second-mini;
            Node*node=q.front().first;
            q.pop();
            if(i==0){
                first=cur_id;
            }
            if(i==size-1){
                last=cur_id;
            }
            if(node->left){
                q.push({node->left,cur_id*2+1});
            }
            if(node->right){
                q.push({node->right,cur_id*2+2});
            }
        }
        ans=max(ans,last-first+1);

    }
    return ans;
}

int main(){
    Node*root=NULL;
    root=build_tree(root);
    int width=maximum_width(root);
    cout<<width<<endl;
}