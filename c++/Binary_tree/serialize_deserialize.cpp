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
 // Encodes a tree to a single string.
    string serialize(Node* root) {
        if(root==NULL){
            return "";
        }
        queue<Node*> q;
        q.push(root);
        string s="";
        s.append(to_string(root->data)+',');
        while(!q.empty()){
            Node*temp=q.front();
            q.pop();
            if(temp->left!=NULL){
                q.push(temp->left);
                s.append(to_string(temp->left->data)+',');
            }else{
                s.append("#,");
            }
            if(temp->right!=NULL){
                q.push(temp->right);
                 s.append(to_string(temp->right->data)+',');
            }else{
               s.append("#,");
            }

        }
        return s;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if(data.size()==0){
            return NULL;
        }
        stringstream s(data);
        string str;
        getline(s,str,',');
        Node*root=new Node(stoi(str));
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node*node=q.front();
            q.pop();

            getline(s,str,',');
            if(str=="#"){
                node->left=NULL;
            }else{
                Node*leftnode=new Node(stoi(str));
                node->left=leftnode;
                q.push(leftnode);
            }

            getline(s,str,',');
            if(str=="#"){
                node->right=NULL;
            }else{
                Node*rightnode=new Node(stoi(str));
                node->right=rightnode;
                q.push(rightnode);
            }

        } 
        return root;
        }

int main(){
    Node*root=NULL;
    root=build_tree(root);
    

}