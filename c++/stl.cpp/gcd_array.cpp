#include<bits/stdc++.h>
using namespace std;//pre computation techniques
int main (){
    int t;
    cin>>t;
    int n;
    cin>>n;
    int a[n+10];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int forward[n];
    forward[1]=a[1];
    for(int i=2;i<=n;i++){
        forward[i]=__gcd(a[i],forward[i-1]);
    }
    int backward[n];
    backward[n]=a[n];
    for(int i=n-1;i>=1;--i){
        backward[i]=__gcd(a[i],backward[i+1]);
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        int gc1=forward[l-1];
        int gc2=backward[r+1];
        int gc=__gcd(gc1,gc2);
        cout<<gc<<endl;
    }
}