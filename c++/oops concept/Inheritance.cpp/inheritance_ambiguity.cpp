#include<bits/stdc++.h>
using namespace std;

class A{

    public : 

    void fun(){
        cout<<"hello from class A"<<endl;
        return ;
    }
};

class B{

    public : 

    void fun(){
        cout<<"hello from class B"<<endl;
        return ;
    }
};

class C : public A, public B{

};

int main(){

    C c1 ;
    c1.A::fun();
    c1.B::fun();
}