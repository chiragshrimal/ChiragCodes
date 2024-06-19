#include<bits/stdc++.h>
using namespace std;

// there are n children and k toffees k<n count the number of ways 
//to distribute toffee among n students
//n<=10^6,  k<n<10^6 , m=10^9 +7
// solution is (nCk)%m
const int m=1e9+7;
const int N=1e6+10;

int binary_exponential(int a,int b){
    int result=1;
    while(b){
        if(b&1==1){
            result=(result*1ll*a)%m;
        }
        a=(a*1ll*a)%m;
        b>>1;
    }
    return result;
}


int main(){

    int fact[N+1];
    fact[0]=1;
    for(int i=1;i<N+1;i++){
        fact[i]=(fact[i-1]*1ll*i)%m;
    }
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        int numrater=fact[n]%m;
        int denominature=(fact[n-k]*1ll*fact[k])%m;
        denominature=binary_exponential(denominature,m-2);
        cout<<(numrater*1ll*denominature)%m<<endl;

    }

}