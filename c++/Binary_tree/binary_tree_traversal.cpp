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
// build the tree 
// if we pass &root then root->left likhne ki jarurat nhi hai 
Node*build_tree(Node* &root){
    cout<<"enter data"<<endl;
    int val;
    cin>>val;
    // stopping criteria;
    if(val==-1){
        return NULL;   
    }
    root=new Node(val);
    cout<<"enter left child"<<endl;   
    root->left=build_tree(root->left);
    cout<<"enter right child"<<endl;
    root->right=build_tree(root->right);
    return root;
}
// preorder traversal
// time complexity is O()
// space complexity is O(1)
void preordertraversal(Node*root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preordertraversal(root->left);
    preordertraversal(root->right);
    return ;
}
// post order traversal
// time complexity is O()
// space complexity is O()
void postordertraversal(Node*root){
    if(root==NULL){
        return ;
    }
    postordertraversal(root->left);
    postordertraversal(root->right);
    cout<<root->data<<" ";
    return ;
}
// inorder traversal 
// time complexity is o()
// space complexity is o()
void inordertraversal(Node*root){
    if(root==NULL){
        return ;
    }
    inordertraversal(root->left);
    cout<<root->data<<" ";
    inordertraversal(root->right);
    return ;
}
// level order traversal 
// time complexity is O()
// space complexity is O(n)// n is number of nodes
void levelordertraversal(Node*root){
    queue<Node*> q;
    if(root!=NULL){
        q.push(root);
    }
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return ;
}
// level order traversal
// if we want to print level wise
// time complexity is O()
// space complexity is O()
void levelwisetraversal(Node*root){
    queue<Node*> q;
    if(root!=NULL){
        q.push(root);
    }
    q.push(NULL);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return ;
}
// make tree from level order traversal 
// time complexity is O()
// space complexity is O()
Node*maketree_using_levelorder(Node*root){
    cout<<"enter data"<<endl;
    int val;
    cin>>val;
    root=new Node(val);
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        cout<<"enter left data"<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1){
        temp->left->data=leftdata;
        q.push(temp->left);
        }
        cout<<"enter right data"<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1){
        temp->right->data=rightdata;
        q.push(temp->right);
        }
    }
    return root;
}
//store level order traversal
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
int main(){
    Node*root=NULL;
    root=build_tree(root);
    // pre order traversal
    preordertraversal(root);
    cout<<endl;
    // post order traversal
    postordertraversal(root);
    cout<<endl;
    // inorder traversal
    inordertraversal(root);
    cout<<endl;
    // level order traversal
    levelordertraversal(root);
    cout<<endl;

    // level wise traversal
    levelwisetraversal(root);

    // // generate tree from level order traversal
    // maketree_using_levelorder(root);

    // level order traversal
    vector<vector<int>> ans=store_level_order(root);
    for(auto it : ans){
        for(auto it1 : it ){
            cout<<it1<<" ";
        }
        cout<<endl;
    }
}
// 5
// 4
// 3
// -1
// -1
// 6
// -1
// -1
// 2
// -1
// -1

