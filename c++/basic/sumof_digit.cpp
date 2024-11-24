#include<bits/stdc++.h>
using namespace std;
int main (){
    int n;
    cout<<"enter a number";
    cin>>n;
    int sum=0;
    while (n>0)
    {
        int lastdigit=n%10;
        n=n/10;
    }
    cout<<"sum is :"<<sum<<endl;
    
}