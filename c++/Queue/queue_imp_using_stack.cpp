#include<bits/stdc++.h>
using namespace std;

// time complexity is O(2*n)
// space compelxity is O(n+n)

class Queue{
    stack<int> s1;
    stack<int> s2;
    int cur_size=0;

    public :
    void push(int x){
        s1.push(x);
        cur_size++;
        return ;
    }

    void pop(){
        if(cur_size>0){
        if(!s2.empty()){
            s2.pop();
        }else{
            while(!s1.empty()){
                int temp=s1.top();
                s1.pop();
                s2.push(temp);
            }
            s2.pop();
        }
        cur_size--;
    }
        return ;
    }

    int top_element(){
        if(cur_size==0){
            cout<<"you an not see top element "<<endl;
            return -1;
        }
        if(!s2.empty()){
            return s2.top();
        }else{
            while(!s1.empty()){
                int temp=s1.top();
                s1.pop();
                s2.push(temp);
            }
        }
        return s2.top();
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
    cout<<q.top_element()<<endl;
    q.push(0);
    q.pop();
    q.pop();
    cout<<q.top_element()<<endl;
}