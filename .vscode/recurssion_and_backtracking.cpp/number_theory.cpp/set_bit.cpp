#include<bits/stdc++.h>
using namespace std;
void print_binary(int n){
    for(int i=5;i>=0;i++){
        cout<<(((n>>i)&1));
    }
    return ;
}
int main (){
    // how to check hat bit is set or not
    int n;
    cin>>n;
    print_binary(n);
    int i;
    cin>>i;
    if((n&(1<<i))==0){
        cout<<"bit is unset"<<endl;
    }else{
        cout<<"bit is set"<<endl;
    }
    //set bit
    n=(n|(1<<i));
    print_binary(n);
}