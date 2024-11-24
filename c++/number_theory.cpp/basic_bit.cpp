#include<bits/stdc++.h>
#include <bitset>
using namespace std;

// decimal to binary
// time compexity is O(log(n))
// space complexity is O(log(n))

// maximum size of vector we can alloacated as globally is O(10^9)
vector<int> v;
void f(int n){
    if(n==1){
        v.push_back(n);
        return ;
    }  
    int rem= n%2;
    n=n/2;
    f(n);
    v.push_back(rem);

}
// time comlexity is O(n)
// space complexity is O(1)
void binary_to_decimal(int n){
    int m=n;
    while(n){
        int rem=n%2;
        n=n/2;
        v.push_back(rem);
    }
    reverse(v.begin(),v.end());
}


// two types of integer 
// 1. signed //2. unsignned
int main (){
    f(11);
    for(auto value : v){
        cout<<value;
    }
    cout<<endl;
    cout<<INT_MAX<<endl;
    // int a= (1<<31)-1;//signed
    // because (1<<31) overflow kar jayeag warning aayegi 
    // cout<<a<<endl;
    // because signed integer m one bit for sign of  integer 
    int b= (1ll<<31)-1;// toh under ki calculation wo long long m krlo
    cout<<b<<endl;
    unsigned int aa=1;
    aa=aa<<32;
    cout<<aa<<endl;
    int bb=aa;
    cout<<bb<<endl;
    bitset<32> bb_bit(bb);// convert integer to 32-bit bitset 
    bb=bb>>1;
    bb=bb|1;
    bb=bb>>1;
    bb=bb<<3;

    bitset<32> bb2(bb);
    cout<<bb2<<endl;
    cout<<"bb=  "<<bb<<endl;

    cout<<b<<endl;
    unsigned int bbbb= (1ll<<32)-1;//1<<32C----> RANGE SE BAHAR CHALA GYA 
    cout<<bbbb<<endl;
}