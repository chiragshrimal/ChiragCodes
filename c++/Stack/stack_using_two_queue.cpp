#include<bits/stdc++.h>
using namespace std;

// time complextiys is O(N)
// space complextiyss is O(2*N)
class Stack{
    queue<int> q1;
    queue<int> q2;
    int cur_size=0;

    public : 
    void push(int x){
        if(q1.empty()){
            q1.push(x);
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }else{
            q2.push(x);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
        }
        cur_size++;
        return ;
    }
    void pop(){
        if(cur_size==0){
            cout<<"stack is already empty"<<endl;
            return ;
        }
        if(q1.empty()){
            q2.pop();
        }else{
            q1.pop();
        }
        cur_size--;
        return ;
    }

    int top(){
        if(q1.empty()){
            return q2.front();
        }
        return q1.front();
    }

    int size(){
        return cur_size;
    }
};

int main(){

    Stack s;
    s.push(4);
    s.push(9);
    s.push(2);
    s.push(5);
    cout<<s.top()<<endl;
    s.pop();
    s.pop();
    cout<<s.top()<<endl;
    s.push(1);
    cout<<s.top()<<endl;

}