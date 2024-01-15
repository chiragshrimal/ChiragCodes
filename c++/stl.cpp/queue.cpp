#include<bits/stdc++.h>
using namespace std;
int main(){
    //works on fifo
    //implimentation of stack
    queue<string> q;
    q.push("chirag");
    q.push("chavi");
    q.push("palasha");
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }

}