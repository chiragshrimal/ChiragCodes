#include<bits/stdc++.h>
using namespace std;

void f(int i,int n){
if(i==0){
    return ;
}
cout<<i<<endl;
i--;
f(i,n);

}
int main(){
    int n;
    cout<<"enter a number "<<endl;
    cin>>n;
    f(n,n);

}