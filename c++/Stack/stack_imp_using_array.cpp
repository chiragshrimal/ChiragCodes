#include<bits/stdc++.h>
using namespace std;


// time complexity is O(1)
// space complexity is O(1)

// in this intial size of the array is fixed so static 
class Stack{
    int st[20];
    int t=-1;
    int cur_size=0;

    public : 
    void push(int x){
        if(cur_size==sizeof(st)/sizeof(int)){
            cout<<"stack overflow"<<endl;
            return ;
        }
        t++;
        st[t]=x;
        cur_size++;
        return;
    }
    void pop(){
        if(cur_size==0){
            cout<<"No element in the stack"<<endl;
            return ;
        }
        t--;
        cur_size--;
        return ;
    }

    int top(){
        if(cur_size==0){
            cout<<"you can not see because stack in empty"<<endl;
            return -1;
        }
        return st[t];
    }

    int size(){
        return cur_size;
    }

    int empty(){
        if(cur_size==0){
            return 1;
        }
        return 0;
    }
};

int main(){
    Stack s;
    s.push(5);
    s.push(2);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}

