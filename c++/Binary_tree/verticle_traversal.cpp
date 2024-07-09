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
// verticle traversal
// time complexity is O(n)
// space complexity is O(n)
vector<vector<int>> verticle_traversal(Node*root){
    map<int,map<int,multiset<int>>> m;// verticle and level
    queue<pair<Node*,pair<int,int>>> q;// verticle and level
    vector<vector<int>> ans;
    if(root==NULL){
        return ans;
    }
    q.push(pair(root,pair(0,0)));
    while(!q.empty()){
        auto it =q.front();
        q.pop();
        Node*temp=it.first;
        int y=it.second.first;
        int x=it.second.second;
        m[y][x].insert(temp->data);
        if(temp->left){
            q.push(pair(temp->left,pair(y-1,x+1)));
        }
        if(temp->right){
            q.push(pair(temp->right,pair(y+1,x+1)));
        }
    }
    for(auto p : m){
        vector<int> col;
        for(auto it :p.second ){
            col.insert(col.end(),it.second.begin(),it.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

int main(){
    Node*root=NULL;
    root=build_tree(root);
    vector<vector<int>> ans=verticle_traversal(root);
    for(auto it : ans){
        for(auto it2 : it){
            cout<<it2<< " ";
        }
        cout<<endl;
    }

}