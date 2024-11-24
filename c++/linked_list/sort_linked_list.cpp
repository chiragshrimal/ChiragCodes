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
Node*convert(vector<int>& v){
    int n=v.size();
    Node*head=new Node(-1);
    Node*start=head;
    for(int i=0;i<n;i++){
        Node*temp=new Node(v[i]);
        start->next=temp;
        start=start->next;
    }
    return head->next;
}
//brute force apporach 
// time complexity is O(n*log(n))
// space complexity is O(2*n);

Node*sort_list(Node*head){
    vector<int> v;
    Node*temp=head;
    while(temp!=NULL){
        v.push_back(temp->data);
        temp=temp->next;
    }     
    sort(v.begin(),v.end());
    return convert(v);
}
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
// better apporach 
// time complexity is O(n*n)
// space complexity is O(1)

Node*sort_list_better(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*newhead=sort_list_better(head->next);
    head->next=NULL;
    return merge_two_list(head,newhead);
}

Node* middle_optimal(Node*head){
    Node*slow=head;
    Node*fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
// optimal apporach 
// time complexity is O(n*log(n))
// space complexity is O(log(n))// stack size 

Node*sort_list_optimal(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*mid=middle_optimal(head);
    Node*midnext=mid->next;
    mid->next=NULL;
    Node*head1=sort_list_optimal(head);
    Node*head2=sort_list_optimal(midnext);
    return merge_two_list(head1,head2);
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

    head=sort_list_optimal(head);
    linked_list_traversal(head);
    
}    







