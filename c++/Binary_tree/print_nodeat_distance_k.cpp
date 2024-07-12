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
void makeparent(Node*root,unordered_map<Node*,Node*> &parent){
    queue<Node*> q;
    if(root==NULL){
        return ;
    }
    q.push(root);
    parent[root]=NULL;
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            Node*temp=q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
                parent[temp->left]=temp;
            }
            if(temp->right){
                q.push(temp->right);
                parent[temp->right]=temp;
            }
        }
    }
}
// print all nodes at distance k
// time complexity is O()
// spac ecomplecity is O()
vector<int> Distancek(Node*root ,Node*target,int k){
    unordered_map<Node*,Node*> parent;
    makeparent(root,parent);
    queue<Node*> q;
    unordered_map<Node*,bool> visited;
    visited[target]=true;
    q.push(target);
    int dis=0;
    while(!q.empty()){
        if(dis==k){
            break;
        }
        int size=q.size();
        for(int i=0;i<size;i++){
            Node*temp=q.front();
            q.pop();
            if(temp->left && !visited[temp->left]){
                visited[temp->left];
                q.push(temp->left);
            }
             if(temp->right && !visited[temp->right]){
                visited[temp->right];
                q.push(temp->right);
            }
            if(parent[temp] && !visited[parent[temp]]){
                visited[parent[temp]]=1;
                q.push(parent[temp]);
            }
        }
        dis++;
    }
    vector<int> ans;
    while(!q.empty()){
        ans.push_back(q.front()->data);
        q.pop();
    }
    return ans;
}

int main(){
    Node*root=NULL;
    root=build_tree(root);
    // vector<int> ans=Distancek(root,target,k);
    // for(auto it : ans){
    //     cout<<it<<" ";
    // }

}