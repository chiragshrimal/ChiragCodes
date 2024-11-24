#include<bits/stdc++.h>
using namespace std;

// create node 
class Node{          
    public:
    int data;
    Node* next;

// comparator
   public:
   Node(int data1,Node* next1){
    data=data1;
    next=next1;
   }
   // no argument 
   public:
   Node(){
    data=0;
    next=NULL;
   }
   // without address
   public:
   Node(int data1){
    data=data1;
    next=NULL;
   }
};
// create lnked list 
// time complexity is O(n)
Node* create_linked_list(vector<int>& v){
    int n=v.size();
    if(n==0){
        return NULL;
    }
    Node*head=new Node(v[0]);
    Node*start=head;
    for(int i=1;i<n;i++){
        Node*temp=new Node(v[i]);
        start->next=temp;
        start=temp;
    }
    return head;
}
// traversal of linked list 
// time complexity is o(n)
//space complexity is O(1)
void linked_list_traversal(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<(temp->data)<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
// find length of the linked list 
// time complexity is O(n)
int length_linked_list(Node*head){
    int cnt=0;
    Node*temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
// finding element 
// time complexity is O(n)
//space complexity is O(1)
Node* finding_element(Node*head,int target){
    Node*temp=head;
    while(temp!=NULL){
        if(temp->data==target){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}
// rotate a linked list 
// time complexity is O()
// space compexity is O()
Node*rotate_list(Node*head,int k){
    if(head==NULL || head->next==NULL){
        return head;
    }
    int l=length_linked_list(head);
    int m=k%l;
    if(m==0){
        return head;
    }
    Node*temp1=head;
    Node*temp2=head;
    int cnt=0;
    while(cnt!=m){
        cnt++;
        temp2=temp2->next;
    }
    while(temp2->next){
        temp1=temp1->next;
        temp2=temp2->next;
    }
    temp2->next=head;
    head=temp1->next;
    temp1->next=NULL;
    return head;
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    Node*head=create_linked_list(v);
    linked_list_traversal(head);

    int k;
    cin>>k;
    head=rotate_list(head,k);
    linked_list_traversal(head);
    
}    







