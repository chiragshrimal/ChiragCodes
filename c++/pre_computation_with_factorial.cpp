#include<bits/stdc++.h>
using namespace std;
// given a integer n and find factorial of n 
//and print with %m
//t=1e5;
//n==1e5;
int main(){
    int t;
    cin>>t;
    int N=1e5;
    int a[N]={1};
    int m=179;
    a[1]=1;
    for(int i=2;i<=N;i++){// pre computation use kiya hai ab program ki complexity 1 sec se bhi kam hai 
        a[i]=(a[i-1]*i)%m;
    }//pre computation on 1D array
    while(t--){
        int n;
        cin>>n;
        //int fact=1;
        //for(int i=1;i<=n;i++){//O(n)
          //  fact=(fact*i)%m;
        //}
        cout<<a[n]<<endl;//O(1)
    }
    //time complexity O(t*n)==10^10>>1 sec 
    //time limite eceed 
}