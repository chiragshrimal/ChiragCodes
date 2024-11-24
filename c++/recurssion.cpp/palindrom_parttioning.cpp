#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> s;

bool is_palindrom(int start,int end,string str){
    while(start<=end){
        if(str[start]!=str[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
void f(int ind,string str,vector<string> v){
    if(ind==str.size()){
        s.push_back(v);
        return ;
    }
    for(int i=ind;i<str.size();i++){
        if(is_palindrom(ind,i,str)){
            v.push_back(str.substr(ind,i-ind+1));
            f(i+1,str,v);
            v.pop_back();
        }
    }
}


int main (){
    string str;
    cout<<"enter a string"<<endl;
    cin>>str;
    vector<string> v;
    f(0,str,v);
    for(auto set : s){
        for(auto String : set){
            cout<<String<<",";
        }
        cout<<endl;
    }

}