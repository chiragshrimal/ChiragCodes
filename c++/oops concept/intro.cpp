#include<bits/stdc++.h>
// we can also include the file 
// or either can create in this file 
// #include "Hero.cpp"
using namespace std ;

// class name is always start with capital letter 
class Hero{
    // properties
    private :
    int health;

    public:
    char level;

    void print(){
        cout<<level<<endl;
    }

    int getHealth(){
        return health;
    }
    char getLevel(){
        return level;
    }
    void setHealth(int h){
        health=h;
    }
    void setLevel(char ch){
        level=ch;
    }
};

int main(){
    // create of object of type of Hero
    // statically allocation  
    Hero h1;

    // using get function****
    // gives garbage value because we have not initialized this value 
    cout<<"health of h1 :"<<h1.getHealth()<<endl;

    // use setter *****
    h1.setHealth(70);
    // we can access value of level because it is public 
    h1.level='A';

    cout<<"health is : "<<h1.getHealth()<<endl;
    cout<<"health is : "<<h1.getLevel()<<endl;


    // size of object *****
    // cout<<"size : "<<sizeof(h1)<<endl;

    // cout<<"health is :"<<h1.getHealth()<<endl;
    // cout<<"level is : "<<h1.level<<endl;

    // it gave me ans=8 but i have only used 5 byte of memory 
    // there is a concept name is padding and greedy alignment
    // Padding is the process of inserting unused memory between members of a class or struct to align data properly in memory.
    // 🔧 Why?
// Modern CPUs access memory efficiently if data is aligned to addresses that are multiples of its size (e.g., int should start at address divisible by 4).

// Greedy alignment means the compiler tries to align each member at its required alignment boundary, even if that means inserting more padding.
    cout<<"size of h1 :"<<sizeof(h1)<<endl;



    // Dynamic allocation 
    // a is a pointer which points to a hero type object 
    Hero*a=new Hero; 
    a->setHealth(50);
    a->setLevel('B');
    cout<<"level of a :"<<(*a).level<<endl;
    cout<<"health of a :"<<a->getHealth()<<endl;


}