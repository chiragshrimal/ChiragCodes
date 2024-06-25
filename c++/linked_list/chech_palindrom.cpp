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
Node* middle_optimal(Node*head){
    if(head==NULL){
        return NULL;
    }
    Node*slow=head;
    Node*fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
Node*reverse_recursive_ADV(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*newhead=reverse_recursive_ADV(head->next);
    Node*front =head->next;
    front->next=head;
    head->next=NULL;
    return newhead;
}
// check for palindrom 
// time complexity is O(3*n/2)
// space compelxity is O(1)

bool palindrom_optimal(Node*head){
    if(head==NULL || head->next==NULL){
        return true;
    }
    Node*mid=middle_optimal(head);
    Node*newhead1=reverse_recursive_ADV(mid->next);
    Node*newhead=newhead1;
    mid->next=NULL;
    Node*temp=head;
    while(temp!=NULL && newhead!=NULL){
        if(temp->data!=newhead->data){
            return false;
        }
        temp=temp->next;
        newhead=newhead->next;
    }
    mid->next=reverse_recursive_ADV(newhead1);
    return true;
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

    bool check=palindrom_optimal(head);
    cout<<check<<endl;

    linked_list_traversal(head);
}    







