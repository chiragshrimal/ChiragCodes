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
// morrise inorder traversal 
// time compleoxity is O(n)
// space complexity is O(1)
vector<int> morrise_inorder_traversal(Node*root){
    vector<int> inorder;
    if(root==NULL){
        return {};
    }
    Node*cur=root;
    while(cur!=NULL){
        if(cur->left==NULL){
            inorder.push_back(cur->data);
            cur=cur->right;
        }else{
            Node*temp=cur->left;
            while(temp->right && temp->right!=cur){
                temp=temp->right;
            }
            if(temp->right==NULL){
                temp->right=cur;
                cur=cur->left;
            }else{
                if(temp->right==cur){
                    inorder.push_back(cur->data);
                    temp->right=NULL;
                    cur=cur->right;
                }
            }
        }
    }
    return inorder;
}
// morrise preorder traversal 
// time complexity is O()
// space compelxity is O()
vector<int> morrise_preorder_traversal(Node*root){
    vector<int> inorder;
    if(root==NULL){
        return {};
    }
    Node*cur=root;
    while(cur!=NULL){
        if(cur->left==NULL){
            inorder.push_back(cur->data);
            cur=cur->right;
        }else{
            Node*temp=cur->left;
            while(temp->right && temp->right!=cur){
                temp=temp->right;
            }
            if(temp->right==NULL){
                inorder.push_back(cur->data);
                temp->right=cur;
                cur=cur->left;
            }else{
                if(temp->right==cur){
                    temp->right=NULL;
                    cur=cur->right;
                }
            }
        }
    }
    return inorder;
}


int main(){
    Node*root=NULL;
    root=build_tree(root);
    vector<int> inorder=morrise_inorder_traversal(root);
    for(auto it : inorder){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int> preorder=morrise_preorder_traversal(root);
    for(auto it : preorder){
        cout<<it<<" ";
    }
    

}