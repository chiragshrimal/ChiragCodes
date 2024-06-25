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
// finding middle element of the linked list 
// time complexity is O(3*n/2)
//space complexity is O(1)

int middle_brute(Node*head){
    if(head==NULL){
        return -1;
    }
    if(head->next==NULL){
        return head->data;
    }

    int l=length_linked_list(head);
    int mid=0;
    if(l%2==0){
        mid=l/2;
    }else{
        mid=(l+1)/2;
    }
    int cnt=1;
    Node*temp=head;
    while(cnt!=mid){
        temp=temp->next;
        cnt++;
    }
    return temp->data;
}

//optimal apporach 
//time complexity is O(n)
/// space compelxity is O(1)

int middle_optimal(Node*head){
    if(head==NULL){
        return -1;
    }
    Node*slow=head;
    Node*fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow->data;
}
int main(){