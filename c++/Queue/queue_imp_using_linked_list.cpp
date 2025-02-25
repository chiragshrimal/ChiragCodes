#include<bits/stdc++.h>
using namespace std;


// time complexity is O(1);
// space complexity is O(dependes on operations)
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

class Queue {
    Node*start =NULL ;
    Node*end=NULL;
    int cur_size=0;

public : 
    void push(int x){
        Node* temp=new Node(x);
        if(cur_size==0){
            start=end=temp;
        }else{
            end->next=temp;
            end=temp;
        }
        cur_size++;
        return ;
    }

    void pop(){
        if(cur_size==0){
            cout<<"queue is already empty"<<endl;
            return ;
        }
        Node*temp=start;
        if(cur_size==1){
            start=end=NULL;
        }else{
            start=start->next;
            temp->next=NULL;
        }
        free(temp);
        cur_size--;
        return ;
    }

    int top(){
        if(cur_size==0){
            cout<<"you can not see element "<<endl;
            return -1;
        }
        return start->data;
    }

    int size(){
        return cur_size;
    }
};



int main(){

    Queue q;
    q.push(2);
    q.push(5);
    q.push(6);
    cout<<q.top()<<endl;
    q.push(0);
    q.pop();
    q.pop();
    cout<<q.top()<<endl;
}