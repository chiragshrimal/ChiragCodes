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
// zig zag traversal 
// time complexity is O(n^2)
// space complexity is O(n)
vector<vector<int>> store_level_order(Node*root){
    vector<vector<int>> ans;
    if(root==NULL){
        return ans;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            Node*temp=q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            level.push_back(temp->data);
        }
        ans.push_back(level);
    }
    return ans;
}
// zig _zag traversal
// optimal apporach  apporach 
// time complexity is o(n)
// space compexity is O(2*n)
vector<int> zig_zag_traversal(Node*root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    queue<Node*>q;
    q.push(root);
    bool turn=true;
    while(!q.empty()){
        int size=q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            level.push_back(q.front()->data);
            Node*temp=q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        if(turn==true){
            for(int i=0;i<size;i++){
                ans.push_back(level[i]);
            }
            turn =false;
        }else{
            for(int i=size-1;i>=0;i--){
                ans.push_back(level[i]);
            }
            turn=true;
        }
    }
    return ans;
}
int main(){
    Node*root=NULL;
    root=build_tree(root);
    vector<int> ans=zig_zag_traversal(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

}