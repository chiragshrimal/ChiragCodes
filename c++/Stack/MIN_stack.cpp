#include<bits/stdc++.h>
using namespace std;

class MinStack{
    private : 
    stack<pair<int,int>> s;
    int mini=INT_MIN;
    public:

    void push(int x){
        mini=min(mini,x);
        s.push(pair(x,mini));
        return ;
    }

    void pop(){
        s.pop();
        return ;
    }

    int front(){
        return s.top().first;
    }
    int get_min(){
        return s.top().second;
    }
}

int main(){

}