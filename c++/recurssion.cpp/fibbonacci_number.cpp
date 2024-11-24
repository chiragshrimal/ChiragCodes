#include<bits/stdc++.h>
using namespace std;
int reverse(long long int x) {
        long long int ans=0;
        long long int y=x;
        if(x>(1ll<<31)-1){
            return 0;
        }
        if(x<-(1ll<<31)){
            return 0;
        }
        if(x<0){
            y=-y;
        }
        int count=0;
        long long int z=y;
        while(y){
            count++;
            y=y/10;
        }
        count--;
        long long int a=pow(10,count);
        while(z){
            long long int rem=z%10;
            ans=ans+rem*a;
            a=a/10;
            z=z/10;
        }
        int k=ans;
        return x<0 ?-k:k;
    }
int main(){
    long long int x;
    cin>>x;
    int k=reverse(x);
    cout<<k<<endl;
}