#include<bits/stdc++.h>
using namespace std;

// proteceted is similar like private 
// but some extra condition is that we can access within the child class 

class Human {

    protected :  
    int height;
    int weight; 
    int age ;
 
    int getAge(){
        return this->age ;
    }

    void setWeight(int w){
        this->weight=w;
    }

};

// child class 
//  class class_name : accrss_modifire parent_class(jis bhi class ko nherit krna chahta hai )

class Male : protected Human{

    public :
    string color;

    void sleep(){
        cout<<"male is sleeping"<<endl;
    }
    void printAge(){
        cout<<"printing age "<<endl;
        cout<<this->age<<endl;
        return ;
    }
    int getHeight(){
        return this->height;
    }
};
int main(){

    Male object1;
    cout<<object1.getHeight()<<endl;

    // cout<<object1.age<<endl;
    // cout<<object1.weight<<endl;
    // cout<<object1.height<<endl;

    // cout<<object1.color<<endl;
    // object.setWeight(84);
    // cout<<object1.weight<<endl;
    // object1.sleep();

}