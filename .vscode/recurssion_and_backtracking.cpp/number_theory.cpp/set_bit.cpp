#include<bits/stdc++.h>
using namespace std;
void print_binary(int n){
    for(int i=5;i>=0;i--){
        cout<<(((n>>i)&1));
    }
    return ;
}
int main (){
    // how to check hat bit is set or not
    int n;
    cin>>n;
    print_binary(n);
    cout<<endl;
    int i;
    cin>>i;
    if((n&(1<<i))==0){
        cout<<"bit is unset"<<endl;
    }else{
        cout<<"bit is set"<<endl;
    }
    //set bit;
    n=(n|(1<<i));
    print_binary(n);
    cout<<endl;

    //(1<<n -1)   numbrer of '1' is n;

    //unset the ith bit
    //logic 
    //take and(&) with 111o11 like number ,in this number ith bit is 0
    n=(n&(~(1<<i)));// ~ is convert to whole number to reverse
    print_binary(n);
    cout<<endl;
    //counting set bit 
    //first methord
    int count =0;
    for(int i=0;i<10;i++){
        if(((n>>i)&1)==1){
            count ++;
        }
    }
    cout<<count<<endl;
    // second methord 
    int count2 =0;
    for(int i=0;i<10;i++){
        if((n&(1<<i))!=0){
            count2++;
        }
    }
    cout<<count2<<endl;
}