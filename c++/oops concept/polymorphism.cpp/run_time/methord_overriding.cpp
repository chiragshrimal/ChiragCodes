#include<bits/stdc++.h>
using namespace std;

class Animal{

    public :
    // virtual keyword lgana jaruri hai runtime binding and resolution bhi runtime par hota hai 
    virtual void speak(){
        cout<<"speaking"<<endl;
        return ;
    }
};

class Dog : public Animal{

    public : 

    void speak(){
        cout<<"barking"<<endl;
        return ;
    }
};

int main(){

    Dog d;
    // firt chech kiya jata hai ki ye function child class m hai kya 
    // ydi hai toh use hi call kiya jata hai 
    // otherwise base class ke function ko call kiya jata hai 
    d.speak();
}