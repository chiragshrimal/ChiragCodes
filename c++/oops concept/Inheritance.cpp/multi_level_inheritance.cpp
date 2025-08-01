#include<bits/stdc++.h>
using namespace std;

class Animal{

    public : 
    int age ; 
    int weight; 

    public : 
    void speak(){
        cout<<"animal is speaking "<<endl;
        return ;
    }
};

class Dog : public Animal{

    public : 
    int color ;

    public : 

    void eyeColor(){
        cout<<"brown color"<<endl;
        return ;
    }
};

class GermanShephad : public Dog{

    public : 

    int height;

    public : 

    void bodyColor(){
        cout<<"black color"<<endl;
        return ;
    }
};

int main(){

    GermanShephad g1 ;
    g1.speak();

}