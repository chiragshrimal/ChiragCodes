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
// iterative preorder traversal
// time complexity is O()
//space complexity is O()
void iterative_preorder(Node*root){
    stack<Node*> s;
    if(root==NULL){
        return ;
    }
    s.push(root);
    while(!s.empty()){
        Node*temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
        if(temp->right){
            s.push(temp->right);
        }
        if(temp->left){
        s.push(temp->left);
        }
    }    
    return ;
}
// iterative inorder traversal
void iterative_inorder(Node*root){
    stack<Node*> s;
    if(root==NULL){
        return ;
    }
    s.push(root);
    Node*node=root;
    while(!s.empty()){
        if(node==NULL){
            Node*temp=s.top();
            s.pop();
            cout<<temp->data<<" ";
            node=temp->right;
        }else{
            node=node->left;
        }
        if(node!=NULL){
            s.push(node);
        }
    }
    return ;
}
// post order traversal
// time complexity is O()
// space complexity is O()
vector<int> iterative_postorder_traversal(Node*root){
    vector<int> ans;
    stack<Node*>s;
    Node*cur=root;
    while(!s.empty() || cur!=NULL){
        if(cur!=NULL){
            s.push(cur);
            cur=cur->left;
        }else{
            Node*temp=s.top()->right;
            if(temp==NULL){
                temp=s.top();
                s.pop();
                ans.push_back(temp->data);
                while(!s.empty() && temp==s.top()->right){
                    temp=s.top();
                    s.pop();
                    ans.push_back(temp->data);
                }
            }else{
                cur=temp;
            }

        }
    }
    return ans;
}
// post order traversal using 2 stack 
// time complexity is O()
// space complexity is O()
vector<int> post_order_traversal_using_two_stack(Node*root){
    vector<int> ans;
    stack<Node*> s1;
    stack<Node*> s2;
    if(root==NULL){
        return ans;
    }
    s1.push(root);
    while(!s1.empty()){
        Node*temp=s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left){
            s1.push(temp->left);
        }
        if(temp->right){
            s2.push(temp->right);
        }
    }
    while(!s2.empty()){
        ans.push_back(s2.top()->data);
        s2.pop();
    }
    return ans;
}
int main(){
    Node*root=NULL;
    root=build_tree(root);
    iterative_preorder(root);
    cout<<endl;
    iterative_inorder(root);
    cout<<endl;
    vector<int> v=iterative_postorder_traversal(root);
    for(auto it : v){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int> ans=post_order_traversal_using_two_stack(root);
    for(auto it : ans){
        cout<<it<<" ";
    }
}