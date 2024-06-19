// array pr kuch some operation krne hai 
//or fir maximum element find krna hai 
//operations m==10^5
//n==10^7
#include<bits/stdc++.h>
using namespace std;/////good concept
int main(){
    int n;
    cin>>n;
    long long int arr[n+10];
    for(int i=1;i<=n;i++){
        arr[i]=0;
    }
    int m;
    cin>>m;
    while(m--){
        int a,b,k;
        cin>>a>>b>>k;
        arr[a]+=k;//logic tgda 
        arr[b+1]-=k;
    }
    long long int brr[n+10];
    brr[1]=arr[1];
    for(int i=2;i<=n;i++){//pre fix sum
        brr[i]=brr[i-1]+arr[i];
    }
    int max=*max_element(brr+1,brr+n+1);
    cout<<max<<endl;

}