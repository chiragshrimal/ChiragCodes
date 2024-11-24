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
void store(Node*root,vector<int> &temp,vector<vector<int>>& ans){
    if(root==NULL){
        return ;
    }
    temp.push_back(root->data);
    if(root->left==NULL && root->right==NULL){
        ans.push_back(temp);
        return ;
    }
    store(root->left,temp,ans);
    store(root->right,temp,ans);
    temp.pop_back();
    return ;
}
// print all the path from root to leaf
// time complexity is O(n)
// space complexity is O(n)
vector<vector<int>> find_all_path(Node*root){
    vector<vector<int>> ans;
    vector<int> temp;
    store(root,temp,ans);
    return ans;
}

int main(){
    Node*root=NULL;
    root=build_tree(root);
    vector<vector<int>> ans=find_all_path(root);
    for(auto it : ans){
        for(auto it2 : it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }

}