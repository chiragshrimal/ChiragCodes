#include<bits/stdc++.h>
using namespace std;
int fun(int n){
// time complexity of one function call is O(1)
// time complexity of function is O(n)===== no. of function call*O(1);
    if(n==0){
        return 1;//------>O(1)
    }else{
        return n*fun(n-1);//-----> O(1);
    }
}
int main (){
    // recurrsion
    // jab bhi recurssion ka question ho toh hmesha function ko in terms of function likhne ki kodhidh kro
    

    //time complexity of recursion 
    // 1. number of function calls 
    // 2. time complexcity to complete one function 
    // time complexity of recurssion is O(1*2);

    //example
    int factorial=fun(5);
    cout<<factorial<<endl;
    }