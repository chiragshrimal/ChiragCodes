#include<bits/stdc++.h>
using namespace std;

class Animal{

    public : 
    int age ;
    int weight;

    public : 
    void bark(){
        cout<<"animal is barking  "<<endl;
        return ;
    }
};

class Human{
    
    public : 
    string color;

    public :
    void speak(){
        cout<<"speaking "<<endl;
        return ;
    }
};

// multiple inheritance 

class Hybrid : public Animal , public Human{

};

int main(){

    Hybrid h1 ;
    h1.speak();
    h1.bark();
}