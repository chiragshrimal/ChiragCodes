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
// better apporach 
//time complexity is O(3*n)
// sapce complexity is O(1)

Node*intersection_better(Node*head1,Node*head2){
    int l1=length_linked_list(head1);
    int l2=length_linked_list(head2);
    if(l1==0 || l2==0){
        return NULL;
    }
    Node*temp1=head1;
    Node*temp2=head2;
    if(l2>l1){
        return intersection_better(head2,head1);
    }
    int k=l1-l2;
    int cnt=0;
    while(cnt!=k){
        cnt++;
        temp1=temp1->next;
    }
    while(temp1!=NULL && temp2!=NULL){
        if(temp1==temp2){
            return temp1;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return NULL;
}

// optimal apporach 
// time complexity is O(2*n)
// space complecity is O(1)

Node*intersection_optimal(Node*head1,Node*head2){
    if(head1==NULL || head2==NULL){
        return NULL;
    }
    Node*temp1=head1;
    Node*temp2=head2;
    while(temp1->next!=NULL && temp2->next!=NULL){
        if(temp1==temp2){
            return temp1;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    while(temp1->next!=NULL && temp2->next!=NULL){
        if(temp1->next==NULL){
            temp1=head2;
        }else{
            temp1=temp1->next;
        }

        if(temp2->next==NULL){
            temp2=head1;
        }else{
            temp2=temp2->next;
        }
        if(temp1==temp2){
            return temp1;
        }
    }
    if(temp1==temp2){
        return temp1;
    }
    return NULL;
}
// optimal simple implimentation 
// time complexity is O(n1 +n2)
// space complexity is O(1)

Node*intersection_potimal_simple(Node*head1,Node*head2){
    Node*temp1=head1;
    Node*temp2=head2;
    while(temp1!=temp2){
        temp1=temp1->next;
        temp2=temp2->next;
        if(temp1==temp2){
            return temp1;
        }
        if(temp1==NULL){
            temp1=head2;
        }
        if(temp2==NULL){
            temp2=head1;
        }
    }
    return temp1;
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


}    







