// #include<bits/stdc++.h>
// using namespace std;

// class Node{
//     public :
//     Node*left;
//     int data;
//     Node*right;
//     Node(int val){
//         left=NULL;
//         right=NULL;
//         data=val;
//     }
// };
// Node*build_tree(Node*root){
//     cout<<"enter data"<<endl;
//     int val;
//     cin>>val;
//     // stopping criteria;
//     if(val==-1){
//         return NULL;
//     }
//     root=new Node(val);
//     root->left=build_tree(root->left);
//     root->right=build_tree(root->right);
//     return root;
// }
// Node* calculate(vector<int>& preorder,int prestart ,int preend,vector<int> & inorder,int instart,inend,map<int,int>& m){
//     if(prestart>endstart || instart>inend){
//         return NULL;
//     }
//     Node*root=Node(inorder[instart]);
//     int mid=m[root->data];
//     int size=mid-instart+1;
//     root->left=calculate(preorder,prestart+1,prestart+mid,inorder,instart,mid-1);
//     root->right=calculate(preorder,prestart+size+1,preend,inorder,mid+1,inend);
//     return root;
// }
// // given preorder and postorder construct binary tree
// // time comopelxity is O()
// // space complexity is O()
// Node* buildtree(vector<int> & preorder, vector<int> & inorder){
//     map<int,int> m;
//     for(int i=0;i<inorder.size();i++){
//         m[inorder[i]]=i;
//     }
//     Node*root=calculate(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,m);
//     return root;
// }

// int main(){
//     Node*root=NULL;
//     root=build_tree(root);
//     root=buildtree();

// }