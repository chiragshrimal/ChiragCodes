#include<bits/stdc++.h>
// we can also include the file 
// or either can create in this file 
// #include "Hero.cpp"
using namespace std ;

// class name is always start with capital letter 
class Hero{
    // properties
    private :
    const int health;

    public:
    char*name;
    char level;

    // ye by default constructor hota hai 
    // we can also write rewrite default constructor 
    // ab bydefault wala constructot call nhi hoga 
    Hero() : health(100){
        cout<<"constructor called"<<endl;
        // heap m memory bnayega and return starting address
        name= new char[100];
    }


    // parameterized constructor
    // hum toh upper jo likhi health ko update krna chahte hai 
    // but if we write health =health then it is scoping problem
    Hero(int h): health(h) {
        name=new char[100];
    }

    Hero(int h, char level) : health(h){
        this->level=level;
        name = new char[100];
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
    void setLevel(char ch){
        level=ch;
    }

    void setName(char name[]){
        strcpy(this->name,name);
    }
    
    ~Hero(){
        cout<<"Destructor called"<<endl;
    }
};

int main(){

   Hero a(40,'A');
   Hero b(20,'D');
   char a_name[10]="chirag";
   char b_name[10]="shyam";
   a.setName(a_name);
   b.setName(b_name);
   a.print();
   b.print();


}