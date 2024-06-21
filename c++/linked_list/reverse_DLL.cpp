#include<bits/stdc++.h>
using namespace std;

// create node 
class Node{          
    public:
    int data;
    Node* next;
    Node*back;

// comparator
   public:
   Node(int data1,Node* next1,Node*back1){
    data=data1;
    next=next1;
    back=back1;
   }
   // no argument comparator
   public:
   Node(){
    data=0;
    next=NULL;
    back=NULL;
   }
   // without address comparator
   public:
   Node(int data1){
    data=data1;
    next=NULL;
    back=NULL;
   }
};
// create doubly linked list 
// time complexity is O(n)
Node* create_linked_list(vector<int>& v){
    int n=v.size();
    if(n==0){
        return NULL;
    }
    Node*head=new Node(v[0]);
    Node*start=head;
    for(int i=1;i<n;i++){
        Node*temp=new Node(v[i],NULL,start);
        start->next=temp;
        start=temp;
    }
    return head;
}
// traversal of linked list 
// in doubly linked list we can  move in both direction
// time complexity is o(n)
//space complexity is O(1)
void linked_list_traversal(Node*head){// forward direction 
    Node*temp=head;
    while(temp!=NULL){
        cout<<(temp->data)<<" ";
        temp=temp->next;
    }
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
// brute force apporach 
// time complexity is O(n)
//space complexity is O(n)
Node* reverse_DLL_brute(Node*head){
    Node*temp=head;
    if(head==NULL || head->next==NULL){
        return head;
    }
    vector<int> ans;
    while(temp){
        ans.push_back(temp->data);
        temp=temp->next;
    }
    reverse(ans.begin(),ans.end());
    temp=head;
    int i=0;
    while(temp){
        temp->data=ans[i];
        i++;
        temp=temp->next;
    }
    return head;
}
// better apporach 
// time complexity is O(5*n/2)
//space complexity is O(1)
Node* reverse_better(Node*head){
    int n=length_linked_list(head);
    Node*start=head;
    Node*end=head;
    while(end->next){
        end=end->next;
    }
    int cnt=0;
    while(cnt<=n/2){
        swap(start->data,end->data);
        start=start->next;
        end=end->back;
        cnt++;
    }
    return head;
}
// bad optimal apporach 
// time complexity is O(3*n/2)
// space complexity is O(1)
Node*reverse_optimal(Node*head){
    Node*start=head;
    Node*end=head;
    while(end->next){
        end=end->next;
    }
    while(!(end==start || end->next==start)){
        swap(start->data,end->data);
        start=start->next;
        end=end->back;
    }
    return head;
}
// good optimal apporach 
// time complexity is O(1*n)
// space complexity is O(1)
Node*reverse_optimal2(Node*head){
    Node*temp=head;
    if(head==NULL){
        return NULL;
    }  
    while(temp->next){
        Node*nextpointer=temp->next;
        Node*prepointer=temp->back;
        swap(temp->next,temp->back);
        temp=nextpointer;
    }
    head=temp;
    swap(temp->next,temp->back);
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
    cout<<endl;

    head=reverse_DLL_brute(head);
    linked_list_traversal(head);
    cout<<endl;

    head=reverse_better(head);
    linked_list_traversal(head);
    cout<<endl;

    head=reverse_optimal(head);
    linked_list_traversal(head);
    cout<<endl;

    head=reverse_optimal2(head);      
    linked_list_traversal(head);
}