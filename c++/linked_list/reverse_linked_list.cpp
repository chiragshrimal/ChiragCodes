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

// reverse linked list 
// iterative apporach 
// time complexity is O(n)
// space complexity is O(1)

Node*reverse_iterative(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*pre=NULL;
    Node*cur=head;
    Node*fur=head->next;
    while(fur){
        cur->next=pre;
        pre=cur;
        cur=fur;
        fur=fur->next;
    }
    cur->next=pre;
    pre=cur;
    head=pre;
    return head;
}

// iterative advanced implimentation 

Node*reverse_iterative_adv(Node*head){
    Node*pre=NULL;
    Node*cur=head;
    while(cur){
        Node*front=cur->next;
        cur->next=pre;
        pre=cur;
        cur=front;
    }
    return pre;
}


//recursive apporach 
// time complexity is O(n)
// space complexity is O(stack size())

Node*reverse_recursive(Node*pre,Node*cur){
    if(cur==NULL  || cur->next==NULL){
        return pre;
    }
    Node*front=cur->next;
    cur->next=pre;
    pre=cur;
    cur=front;
    return reverse_recursive(pre,cur);
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

    head=reverse_iterative_adv(head);
    linked_list_traversal(head);

    head=reverse_recursive(NULL,head);
    linked_list_traversal(head);



}