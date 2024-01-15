#include<bits/stdc++.h>
using namespace std;
//modulo property 
// (a+b)%m===(a%m +b%m)%m
// (a*b)%m===((a%m)*(b*m))%m
// (a-b)%m===((a%m)-(b%m)+m)%m
// (a/b)%m===((a%m)*(b^-1)%m)%m
int main  (){
    // Q... find factorial
    // output with modulo
    int m=1e9+7;//very very close to integer and 7 isliye add kiya taki aap odd numbers ka multiplicative inverse find kar skte ho
    int n;
    cin>>n;
    int fact=1;
    for(int i=2;i<=n;i++){
        fact=(fact*i)%m;
    }
    cout<<fact;
}