#include<bits/stdc++.h>
using namespace std;

// time complexity is O(N)
// space complexitys is O(N)

class Stack{
    queue<int> q;
    int cur_size=0;

    public : 
    void push(int x){
        q.push(x);
        cur_size++;
        for(int i=1; i<=cur_size-1;i++){
            int temp=q.front();
            q.pop();
            q.push(temp);
        }
        return;
    }

    void pop(){
        q.pop();
        cur_size--;
        return ;
    }
    int top(){
        return q.front();
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