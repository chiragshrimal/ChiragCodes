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
// merge two linked list
// optimal apporach 
// time complexity is O(m+n)
// sapce complexity is o(1)
Node*merge_two_list(Node*head1,Node*head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    Node*head3=NULL;
    Node*temp=NULL;
    Node*temp1=head1;
    Node*temp2=head2;
    if(temp1->data<=temp2->data){
        temp=head3=temp1;
        temp1=temp1->next;
    }else{
        temp=head3=temp2;
        temp2=temp2->next;
    }
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data<=temp2->data){
            temp->next=temp1;
            temp=temp1;
            temp1=temp1->next;
        }else{
            temp->next=temp2;
            temp=temp2;
            temp2=temp2->next;
        }
    }
    if(temp1){
        temp->next=temp1;
    }
    if(temp2){
        temp->next=temp2;
    }
    return head3;
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
    int m;
    cin>>m;
    vector<int> v2;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        v2.push_back(x);
    }
    Node*head1=create_linked_list(v);
    linked_list_traversal(head1);

    Node*head2=create_linked_list(v2);
    linked_list_traversal(head2);

    Node*head3=merge_two_list(head1,head2);
    linked_list_traversal(head3);
    
}    







