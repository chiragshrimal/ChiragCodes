#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){// normal methord // time complexity is O(n)
int GCD=1;
for(int i=1;i<=max(a,b);i++){
    if((a%i==0)&&(b%i==0)){
        GCD=i;
    }
}
return GCD;
}
int euclid_gcd(int a,int b){// eculid methord // time complexity is O(log(n))
    if(b==0){
        return a;
    }
    return euclid_gcd(b,a%b);
}
// a*b==lcm(a,b)*gcd(a,b)
int lcm(int a,int b){
    int l=(a*b)/euclid_gcd(a,b);
    return l;
}
int main (){
    int a,b;
    cin>>a>>b;
    int g=gcd(a,b);
    cout<<g<<endl;
    int h=euclid_gcd(a,b);
    cout<<h<<endl;
    int l=lcm(a,b);
    cout<<l<<endl;

}