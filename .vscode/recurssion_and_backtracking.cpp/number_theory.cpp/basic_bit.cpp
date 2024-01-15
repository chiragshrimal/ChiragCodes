#include<bits/stdc++.h>
#include <bitset>

using namespace std;
// two types of integer 
// 1. signed //2. unsignned
int main (){
    cout<<INT_MAX<<endl;
    //int a= (1<<32)-1;//signed
    // because isigned integer m one bit for sign of  integer 
    int b= (1ll<<31)-1;

    unsigned int aa=1;
    aa=aa<<31;
    int bb=aa;
    bitset<32> bb_bit(bb);
    bb=bb>>1;
    bb=bb|1;
    bb=bb>>1;
    bb=bb<<4;

    bitset<32> bb2(bb);
    cout<<bb2<<endl;
    cout<<"bb=  "<<bb<<endl;

    cout<<b<<endl;
    unsigned int a= (1ll<<32)-1;//1<<32C----> RANGE SE BAHAR CHALA GYA 
    cout<<a<<endl;
}