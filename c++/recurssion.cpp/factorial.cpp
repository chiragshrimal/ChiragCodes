#include<bits/stdc++.h>
using namespace std;


// using parameter

void f(int n,int fact){
    if(n<1){
        cout<<fact<<endl;
        return; 
    }
    f(n-1,(fact)*n);
}

//using without parameter

int g(int n){
    if(n==0||n==1){
        return 1;
    }
    return g(n-1)*n;
}
int  main(){
    int fact=1;
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    f(n,fact);
    // cout<<fact<<endl;
    int fact2=g(n);
    cout<<fact2<<endl;
}