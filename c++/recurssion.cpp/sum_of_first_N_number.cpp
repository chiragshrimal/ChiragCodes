#include<bits/stdc++.h>
using namespace std;

// using without parameter

int g(int n){
    if(n==0){
        return 0;
    }
    int s=g(n-1)+n;
    return s;
}

//using parameter 
void f(int i,int sum){
  if(i<1){
    cout<<sum<<endl;
    return ;
  }
  f(i-1,sum+i);
}
int main (){
    int sum=0;
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    f(n,sum);
    int sum2=g(n);
    cout<<sum2<<endl;
}