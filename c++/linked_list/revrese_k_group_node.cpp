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
void reverse(Node*head){
    Node*pre=NULL;
    Node*cur=head;
    while(cur){
        Node*fur=cur->next;
        cur->next=pre;
        pre=cur;
        cur=fur;
    }
}
// reeverse the k group node 
// time complexity is O()
// space complexity is O()
Node*reverse_k_group(Node*head,int k){
    Node*temp=head;
    Node*kth_node=head;
    Node*prenode=NULL;
    Node*nextnode=NULL;
    while(temp!=NULL){
        int cnt=1;
        while(cnt!=k && kth_node!=NULL){
            cnt++;
            kth_node=kth_node->next;
        }
        if(kth_node==NULL){
            if(temp==head){
                return head;
            }else{
                prenode->next=temp;
                return head;
            }
        }
        nextnode=kth_node->next;
        kth_node->next=NULL;
        reverse(temp);
        if(prenode){
            prenode->next=kth_node;
        }
        if(temp==head){
            head=kth_node;
        }
        prenode=temp;
        temp=nextnode;
        kth_node=nextnode;
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

    int k;
    cin>>k;
    head=reverse_k_group(head,k);
    linked_list_traversal(head);
    
}