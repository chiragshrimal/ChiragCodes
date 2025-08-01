#include<bits/stdc++.h>
using namespace std;

// function overloading 
// if both function have same name and argument are different or type of argument is 
// different then called function overloading 
// based on return type you can not say function fuction overloading 

class A{

    public : 
    
    void sayHello(string n){
        cout<<"Hello from chirag"<<endl;
        return ;
    }

    int sayHello(string name ){
        cout<<"hello"<<name<<endl;
        return 1;
    }
};


int main(){

    A obj;
    obj.sayHello();
}