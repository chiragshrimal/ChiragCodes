#include<bits/stdc++.h>
using namespace std;
void print_divisor(int n){// o(n^1/2)
     for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cout<<i<<endl;
            if(n/i!=i){
                cout<<n/i<<endl;
            }
        }
    }
}
void prime_divisor(int n){//O(n^1/2)
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            n=n/i;
            cout<<i<<endl;
        }
    }
}
void prime_number(int n){
    for(int i=2;i*i<n;i++){/// O(n^1/2)
        if(n%i==0){
            cout<<"NO"<<endl;
            return ;
    }
    cout<<"yes"<<endl;
    return ;                                                                                                
}
}
int main(){
    int n;
    cin>>n;
    print_divisor(n);
    prime_number(n);
    prime_divisor(n);
   
}