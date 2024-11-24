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
// finding middle element of the linked list 
// time complexity is O(3*n/2)
//space complexity is O(1)

int middle_brute(Node*head){
    if(head==NULL){
        return -1;
    }
    if(head->next==NULL){
        return head->data;
    }

    int l=length_linked_list(head);
    int mid=0;
    if(l%2==0){
        mid=l/2;
    }else{
        mid=(l+1)/2;
    }
    int cnt=1;
    Node*temp=head;
    while(cnt!=mid){
        temp=temp->next;
        cnt++;
    }
    return temp->data;
}

//optimal apporach 
//time complexity is O((n/2)*2)
/// space compelxity is O(1)

Node* middle_optimal(Node*head){
    Node*slow=head;
    Node*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
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

    int brute=middle_brute(head);
    cout<<brute<<endl;

    Node* optimal=middle_optimal(head);
    cout<<optimal->data<<endl;



}    







