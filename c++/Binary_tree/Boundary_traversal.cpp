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
void print_left_part(vector<int>& ans,Node*root){
    if(root==NULL){
        return ;
    }
    Node*temp=root;
    while(temp!=NULL){
        if(temp->left==NULL && temp->right==NULL){
            break;
        }
        ans.push_back(temp->data);
        if(temp->left==NULL){
            temp=temp->right;
        }else{
            temp=temp->left;
        }
    }
}
void print_right_part(vector<int> & ans,Node*root){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return ;
    }
    stack<Node*> s;
    Node*temp=root;
    while(temp!=NULL){
        if(temp->left==NULL && temp->right==NULL){
            break;
        }
        s.push(temp);
        if(temp->right==NULL){
            temp=temp->left;
        }else{
            temp=temp->right;
        }
    }
    while(!s.empty()){
        if(s.top()==root){
            s.pop();
            continue;
        }
        ans.push_back(s.top()->data);
        s.pop();
    }
    return ;
}


void print_leaf_part(vector<int> & ans,Node*root){
    if(root==NULL){
        return ;
    }
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    print_leaf_part(ans,root->left);
    print_leaf_part(ans,root->right);
}
// boundary level order traversal
// time complexity is O(3*n)
// space complexity is O(n            )

vector<int> boundary_level(Node*root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    // // print left part
    print_left_part(ans,root);

    // ptint leaf part
    print_leaf_part(ans,root);

     
    // print right  part;
    print_right_part(ans,root);

    return ans;
}

int main(){
    Node*root=NULL;
    root=build_tree(root);
    vector<int> ans=boundary_level(root);
    for(auto it : ans){
        cout<<it<<" ";
    }

}