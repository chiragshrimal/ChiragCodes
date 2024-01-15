#include<bits/stdc++.h>
using namespace std;
vector<string>valid;
/// jab bhi is tye ka question ho like ek possition pr two chance like dono se possible hop skta hai

void generate(string &s,int open,int close){
    if(open==0 && close==0){
        valid.push_back(s);
        return ;
    }
    if(open>0){
        s.push_back('(');
        generate(s,open-1,close);
        s.pop_back();/////   backtracking 
    }
    if(close>0){
        if(open<close){
            s.push_back('(');
            generate(s,open,close-1);
            s.pop_back();/// backtracking 
        }
    }
}
int main (){
    int n;
    cin>>n;
    int open,close;
    open=close=n;
    string str ;
    generate(str,n,n);
    for(auto value :valid){
        cout<<value<<endl;
    }
}