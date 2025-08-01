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
    char*name;
    char level;
    // create static data member 
    static int timeToComplete;

    // ye by default constructor hota hai 
    // we can also write rewrite default constructor 
    // ab bydefault wala constructot call nhi hoga 
    Hero(){
        cout<<"constructor called"<<endl;
        // heap m memory bnayega and return starting address
        name= new char[100];
    }


    // parameterized constructor
    // hum toh upper jo likhi health ko update krna chahte hai 
    // but if we write health =health then it is scoping problem
    Hero(int health){
        cout<<"this value :"<<this<<endl;
        this->health=health;
    }

    Hero(int health, char level){
        this->health=health;
        this->level=level;
    }
    // own copy consftructor 
    // wese toh by default hota hai bnane ki jarurat nhi hai 
    // object ko by refrence hi pass krna pdega nhi toh infinite loop m fas jayega 
    Hero(Hero &s){
        char*temp=new char[strlen(s.name)+1];
        strcpy(temp,s.name);
        this->name=temp;
        cout<<"copy constructor called "<<endl;
        this->health=s.health;
        this->level=s.level;
    }

    void print(){
        cout<<"name is :"<<this->name<<endl;
        cout<<"health is :"<<this->health<<endl;
        cout<<"level is :"<<this->level<<endl;
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

    void setName(char name[]){
        strcpy(this->name,name);
    }
    
    ~Hero(){
        cout<<"Destructor called"<<endl;
    }

    // in the static function you can only access static data member 
    static void random(){
        cout<<timeToComplete<<endl;
    }
};

// intialization of static data member
int Hero :: timeToComplete=5;

int main(){
    // Access static data member without creating object 
    // or object bnane ke bad bhi is thr se hi access krte hai 
    // because static class ko belong krta hai 
    cout<<Hero::timeToComplete<<endl;

    Hero a;
    // dont access with below thr se 
    // because static class ko belong krta hai 
    cout<<a.timeToComplete<<endl;

}