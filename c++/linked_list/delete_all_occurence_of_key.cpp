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

// delete node from front 
Node* At_first(Node*head){
    Node*temp=head;
    if(head==NULL || head->next==NULL){
        head=NULL;
        return head;
    }
    head=head->next;
    free(head->back);
    head->back=NULL;
    return head;
}
// delete from the end
Node*At_last(Node*head){
    Node*temp=head;
    if(head==NULL){
        return NULL;
    }
    // exactly one element 
    if(head->next==NULL){
        free(head);
        head=NULL;
        return NULL;
    }
    while(temp->next){
        temp=temp->next;
    }
    temp=temp->back;
    free(temp->next);
    temp->next=NULL;
    return head;
}
// delete at position 
Node*delete_position(Node*head,int k){
    if(head==NULL || head->next==NULL){
        if(k==1){
            return NULL;
        }else{
            return head;
        }
    }
    if(k==1){
        head=head->next;
        free(head->back);
        head->back=NULL;
        return head;
    }
    Node*temp=head;
    int cnt=0;
    while(temp){
        cnt++;
        if(cnt==k){
            temp->back->next=temp->next;
            if(temp->next!=NULL){
                temp->next->back=temp->back;
            }
            temp->next=NULL;
            temp->back=NULL;         
            free(temp);
            break;
        }
        temp=temp->next;
    }
    return head;
}
// insert at first 
Node*insert_first(Node*head,int x){
    Node*temp=head;
    Node*var=new Node(x);
    if(head==NULL){
        return var;
    }
    head->back=var;
    var->next=head;
    head=var;
    return head;
}
// insert at last
Node*insert_last(Node*head,int x){
    Node*temp=head;
    Node*var=new Node(x);
    if(head==NULL){
        head=var;
        return head;
    }
    while(temp->next){
        temp=temp->next;
    }
    temp->next=var;
    var->back=temp;
    return head;
}
// insert at position 
Node*insert_position(Node*head,int x,int k){
    Node*temp=head;
    Node*var=new Node(x);
    if(head==NULL){
        if(k==1){
            return var;
        }else{
            return head;
        }
    }
    if(k==1){
        head->back=var;
        var->next=head;
        head=var;
        return var;
    }
    int cnt=0;
    while(temp){
        cnt++;
        if(cnt==k){
            temp->back->next=var;
            var->back=temp->back;
            var->next=temp;
            temp->back=var;
            break;
        }
        temp=temp->next;
    }
    return head;
}
// insert at given node 
Node* insert_node(Node*node,int  x){
    Node*var=new Node(x);
    node->back->next=var;
    var->back=node->back;
    var->next=node;
    node->back=var;
}

// delete all occurences of the key in the ll
// time complexity is O(n)
// space complexity is O(1)

Node*delete_key(Node*head,int key){
    Node*temp=head;
    while(temp){
        if(temp->data==key){
            if(temp==head){
                head=head->next;
            }
            Node*pre=temp->back;
            Node*fur=temp->next;
            if(pre!=NULL){
                pre->next=fur;
            }

            if(fur!=NULL){
                fur->back=pre;
            }
            temp=fur;
        }else{
            temp=temp->next;
        }
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
    cout<<endl;

    // // delete from front 
    // head=At_first(head);
    // linked_list_traversal(head);
    // cout<<endl;

    // // delete from the end
    // head=At_last(head);
    // linked_list_traversal(head);


    // delete position  
    // int k;
    // cin>>k;
    // head=delete_position(head,k);
    // linked_list_traversal(head);

    // insert at first
    int x;
    cin>>x;
    // head=insert_first(head,x);
    // linked_list_traversal(head);

    //insert at possiton 
    // int k;
    // cin>>k;
    // head=insert_position(head,x,k);
    // linked_list_traversal(head);


    // insert at the given node
    insert_node(head->next->next,x);
    linked_list_traversal(head);


}