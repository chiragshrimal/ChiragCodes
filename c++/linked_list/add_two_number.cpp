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
// optimal apporach 
// time complexity is O(max(n1,n2))
// space complexity is O(1) only use required linked list
Node*add_two_Number(Node*head1,Node*head2){
    Node*head3=NULL;
    Node*temp3=head3;
    Node*temp1=head1;
    Node*temp2=head2;
    int carry=0;
    int cnt=0;
    while(temp1!=NULL && temp2!=NULL){
        cnt++;
        int a=temp1->data +temp2->data;
        int x=(a+carry)%10;
        carry=(a+carry)/10;
        Node*temp=new Node(x);
        if(cnt==1){// first time 
            temp3=head3=temp;
        }else{
            temp3->next=temp;// other time  
        }
        temp3=temp;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    while(temp1){
        cnt++;
        int a=temp1->data;
        int x=(a+carry)%10;
        carry=(a+carry)/10;
        Node*temp=new Node(x);
        if(cnt==1){
            temp3=head3=temp;
        }else{
            temp3->next=temp;
        }
        temp3=temp;
        temp1=temp1->next;
    }
    while(temp2){
        cnt++;
        int a=temp2->data;
        int x=(a+carry)%10;
        carry=(a+carry)/10;
        Node*temp=new Node(x);
        if(cnt==1){
            temp3=head3=temp;
        }else{
            temp3->next=temp;
        }
        temp3=temp;
        temp2=temp2->next;
    }
    if(carry!=0){
        temp3->next=new Node(carry);
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
    vector<int> v2;
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        v2.push_back(x);
    }
    Node*head1=create_linked_list(v);
    linked_list_traversal(head1);

    Node*head2=create_linked_list(v2);
    linked_list_traversal(head2);

    Node*head3=add_two_Number(head1,head2);
    linked_list_traversal(head3);

}    