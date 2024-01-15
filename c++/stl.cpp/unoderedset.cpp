#include<bits/stdc++.h>
using namespace std;
int main(){
    //same as unordered map
    //inbuilt implimentation of hashing 
    //insertion and find,erase o(1)
    //store in random order
    //unique key store 
    //we can create that data type of unordered map which has aiready exist hash fuction 
    unordered_set<string> s;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string str;
        cin>>str;
        s.insert(str);
    }
    int x;
    cin>>x;
    for(int i=1;i<=x;i++){
        string str;
        cin>>str;
        auto it=s.find(str);
        if(it!=s.end()){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}