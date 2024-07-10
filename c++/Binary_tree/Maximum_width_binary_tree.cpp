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
// time complexity is O()
// space complexity is O()
int maximum_width(Node*root){
    queue<Node*> q;
    if(root==NULL){
        return 0;
    }
    int w=0;
    q.push(root);
    while(!q.empty()){
        int cursize=q.size();
        vector<Node*> row;
        for(int i=0;i<cursize;i++){
            row.push_back(q.front());
            Node*temp=q.front();
            q.pop();
            if(temp==NULL){
                continue;
            }
            q.push(temp->left);
            q.push(temp->right);
        }
        int i=0;
        int j=row.size()-1;
        while(i<=j){
            if(row[i]==NULL){
                i++;
            }
            if(row[j]==NULL){
                j--;
            }
            if(row[i]!=NULL && row[j]!=NULL){
                break;
            }
        }
        w=max(w,j-i+1);
    }
    return w;
}


int main(){
    Node*root=NULL;
    root=build_tree(root);

}