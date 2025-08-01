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
};

int main(){

    cout<<"start"<<endl;
    // statically allocation 
    
    Hero h1(30) ;
    cout<<"address of h1 :"<<(&h1)<<endl;
    cout<<"end"<<endl;

    // dynamically allocation 
    // below both are same 
    Hero *h2=new Hero;
    Hero *h3=new Hero(70);
    cout<<"address of h3 hero : "<<h3<<endl;

    Hero temp(50,'C');
    cout<<"health of Temp :"<<temp.getHealth()<<endl;
    cout<<"level of temp  :"<<temp.getLevel()<<endl;
    temp.print();


    // copy constructor
    // ye bhi inbuild hota hai 
    // also we can create 
    // we are creating the same object 
    // Hero ramesh(*h3);
    // when we are creating the object that time we have to pass the object(jiske jaisa hme bnana hai )
    // we can write in both the ways
    Hero ramesh(h1);
    // Hero ramesh=h1 ;
    ramesh.print();


    // concept of shallow copy 
    // which created by the default copy constructor

    Hero hero1;
    hero1.setHealth(70);
    hero1.setLevel('A');
    char name[7]="chirag";
    hero1.setName(name);
    hero1.print();

    // copy the hero1 into hero2 using by default constructor 
    Hero hero2(hero1);
    hero2.print();

   
    // so above situation se bchne ke liye deep copy ka use kiya jata hai 
    // uskme hme khudka copy constructor use krte hai 
    // because usme hum same memory ka use  nhi krte jo shallow copy m use hota hai 

    // ab hero2 m value change nhi hogi 
    hero1.name[0]='a';
    hero1.level='X';
    hero2.print();
    hero1.print();


    // copy assignmet operator 
    hero1=hero2;
    hero1.print();
    hero2.print();


    // Destructor 
    // it is like a  constructor 
    // ek hi bar object ke end hone par call hota hai 
    // statically 
    // static ke liye destructor automatically call ho jata hai 
    Hero d;

    // Dynamically
    // Dynamic ke liye manually call krna pdta hai 
    Hero *c=new Hero();
    // manually called 
    delete c;
    return 0;


}