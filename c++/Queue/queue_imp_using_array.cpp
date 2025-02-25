#include<bits/stdc++.h>
using namespace std;


// time complexity is O(1)
// space compelxity is O(size of array);

// in case of array intial we have to fix the size of the array so static 
class Queue{
    int q[20];
    int start=-1;
    int end =-1;
    int cur_size=0;

    public : 
    void push(int x){
        if(cur_size==(sizeof(q)/sizeof(int))){
            cout<<"queue is overflow "<<endl;
            return;
        }
        if(cur_size==0){
            end=0;
            start=0;
        }else{
            end=(end+1)%(sizeof(q)/sizeof(int));
        }

        q[end]=x;
        cur_size++;

        return;
    }
    
    void pop(){
        if(cur_size==0){
            cout<<"queue is already empty "<<endl;
            return;
        }
        if(cur_size==1){
            start=-1;
            end=-1;
        }else{
            start=(start+1)%(sizeof(q)/sizeof(int));
        }
        cur_size--;
        return;
    }
    int top(){
        if(cur_size==0){
            cout<<"you can not see top element "<<endl;
            return -1;
        }
        return q[start];
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