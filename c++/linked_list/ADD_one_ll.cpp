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

// ADD one to linked list 
// time complexity is O()
// space complexity is O()

Node*add_one_better(Node*head){
    Node*newhead=reverse_recursive_ADV(head);
    Node*temp=newhead;
    int carry=0;
    Node*pre=NULL;
    while(temp){
        int a=temp->data+1;
        int x=a%10;
        carry=a/10;
        pre=temp;
        temp->data=x;
        temp=temp->next;
        if(carry==0){
            break;
        }
    }
    if(carry!=0){
        pre->next=new Node(carry);
    }
    head=reverse_recursive_ADV(newhead);
    return head;
}

int f(Node*head){
    if(head==NULL){
        return 1;
    }
    if(head->next==NULL){
        int a=head->data +1;
        int x=a%10;
        head->data=x;
        int carry=a/10;
        return carry;
    }
    int carry=f(head->next);
    if(carry==0){
        return 0;
    }
    int a=head->data +carry;
    int x=a%10;
    head->data=x;
    carry=a/10;
    
    return carry;
}
//optimal apporach 
//time complexity is O(2*n)
// space compelcity is o(stack size());

Node*add_one_optimal(Node*head){
    int carry=f(head);
    if(carry!=0){
        Node*var=new Node(carry);
        var->next=head;
        head=var;
    }
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

    // head=add_one_better(head);
    // linked_list_traversal(head);

    head=add_one_optimal(head);
    linked_list_traversal(head);

}    







