#include<bits/stdc++.h>
using namespace  std;


// time  ecomplexity is O(1)
// space  complexity is O(depends on operations )
class Node{   
    public :       
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


class Stack{
    Node* top_pointer=NULL;
    int cur_size=0;

    public :
    void push(int x){
        Node*temp=new Node(x);
        temp->next=top_pointer;
        top_pointer=temp;
        cur_size++;
        return ;
    }

    void pop(){
        if(top_pointer==NULL){
            cout<<"stack is already empty "<<endl;
            return ;
        }
        Node*temp=top_pointer;
        top_pointer=top_pointer->next;
        cur_size--;
        free(temp);
        return ;
    }

    int top(){
        if(top_pointer==NULL){
            cout<<"you can not see top_pointer element "<<endl;
            return -1;
        }
        return top_pointer->data;
    }

    int size(){
        return cur_size;
    }
};
int main(){

    Stack s;
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
}