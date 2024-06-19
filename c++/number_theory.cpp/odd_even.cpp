#include<bits/stdc++.h>
using namespace  std ;
int main (){
    // modular,division function ka use kam kro 
    //because ye slow hote hai 
    int n;
    cin >>n;
    if((n&1)==1){
        cout<<"odd";
    }else{
        cout<<"even";
    }
    // for division by 2;
    n=n>>1;
    // check power of two 
    if((n&(n-1))==0){
        cout<<"power of 2";
    }else{
        cout<<"not power of 2";
    }
    

}