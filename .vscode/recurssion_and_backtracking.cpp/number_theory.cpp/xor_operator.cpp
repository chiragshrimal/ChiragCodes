#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    //same same pr ans zero aata hai
    //different different pr 1 aata hai 
    //0^a=a;
    // a^a=0;
    // a^a^a......a odd times===a;
    // a^a^......a even times==0;
    // toggle the bit
    //a^(1<<i)

    //find unique elment in an array
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum^a[i];
    }
    cout<<sum<<endl;


    //swaping usig xor operater
    int p,q ;
    cin>>p>>q;
    cout<<p<<" "<<q<<endl;
    p=p^q;
    q=p^q;//===p
    p=p^q;
    cout<<p<<" "<<q<<endl;


}