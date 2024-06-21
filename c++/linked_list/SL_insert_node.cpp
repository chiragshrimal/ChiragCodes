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
// insert at last of the linked list 
// time complexity is O(n)
Node* Atlast(Node*head,int x){
    Node*temp=head;
    Node*var=new Node(x);
    if(temp==NULL){
        return var;
    }
    while(temp->next){
        temp=temp->next;
    }
    temp->next=var;
    return head;

}
// at initially 
// time complexity is O(1)

Node*Atfirst(Node*head,int x){
    Node*temp=head;
    Node*var=new Node(x);
    if(temp==NULL){
        return var;
    }
    var->next=head;
    head=var;
    return head;
}

// insert at some position 
Node*At_position(Node*head,int k,int x){
    Node*temp=head;
    Node*var=new Node(x);
    if(temp==NULL){
        if(k==1){
        head=var;
        return head;
        }else{
            return NULL;
        }
    }
    if(k==1){
        var->next=head;
        head=var;
        return head;
    }
    int cnt=0;
    while(temp){
        cnt++;
        // cout<<cnt<<endl;
        if(cnt==k-1){
            // cout<<cnt<<endl;
            var->next=temp->next;
            temp->next=var;
            break;
        }
        temp=temp->next;
    }
    return head;
}
// insert target
// before target;
Node* insert_target(Node*head,int target,int x){
    Node*temp=head;
    Node*var=new Node(x);
    if(head==NULL){
        head=var;
        return head;
    }
    if(head->data==target){
        var->next=head;
        head=var;
        return head;
    }
    Node*pre=NULL;
    while(temp){
        if(temp->data==target){
            var->next=pre->next;
            pre->next=var;
            break;
        }
        pre=temp;
        temp=temp->next;
    }
    return head;
}



// delete the node
Node* At_front_delete(Node*head){
    if(head==NULL){
        return NULL;
    }
    Node*temp=head->next;
    head->next=NULL;
    head=temp;
    return head;
}
// at last
Node* At_last_delete(Node*head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node*temp=head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}
// at some value 
// in linked list elements are unique 
Node*At_value_delete(Node*head,int target){
    Node*temp=head;
    // if it is front element
    if(temp->data==target){
        Node*temp=head->next;
        head->next=NULL;
        head=temp; 
        return head;
    }
    while(temp){
        if(temp->next->data==target){
            break;
        }
        temp=temp->next;
    }
    // At any possition 
    Node*var=temp->next->next;
    temp->next->next=NULL;
    temp->next=var;
    return head;
}


int main(){
    // Node node;// constructor call hoga 
    // Node*n1=new Node();
    // Node*n2;// no constructor call 
    // cout<<(n1->data)<<endl;
    // cout<<(node.data)<<endl;
    // cout<<(n2->data)<<endl;
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    Node*head=create_linked_list(v);
    // insertion the node 

    // int x;
    // cin>>x;

    // at the last
    // Node* last=Atlast(head,x);
    // linked_list_traversal(last);


     // at the first
    // Node* first=Atfirst(head,x);
    // linked_list_traversal(first);


    // at some position
    int k;
    cin>>k;
    int x;
    cin>>x;
    // head=At_position(head,k,x);
    // linked_list_traversal(head);

    // At before target 
    head=insert_target(head,k,x);
    linked_list_traversal(head);


    // delete the node 
    // 1. at the front 





    // 2. at the last
    // 3. at any possition 
    // 4. basis of value 



}    







