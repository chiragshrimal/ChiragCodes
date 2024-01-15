#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<char,int> m={{'{',-1},{'[',-2},{'(',-3},{'}',1},{']',2},{')',3}};
    stack<char> s;
    string str;
    cin>>str;
    for(auto value :str){
        if(m[value]<0){
            s.push(value);
        }else{
            if(s.empty()){
                cout<<"NO"<<endl;
                return 0;
            }else{
                char ch=s.top();
                s.pop();
                if(m[ch]+m[value]!=0){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }

        }
    }
    if(s.empty()){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    }