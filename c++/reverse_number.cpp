#include<bits/stdc++.h>
using namespace std;
int main (){
    int n;
    cout<<"enter a number";
    cin>>n;
    int ans=0;
    while(n){
        ans=ans*10+n%10;
        n=n/10;
    }
    cout<<ans<<endl;
}