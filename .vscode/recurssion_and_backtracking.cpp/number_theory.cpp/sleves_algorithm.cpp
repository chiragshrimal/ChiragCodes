#include<bits/stdc++.h>
using namespace std;
//q<=10^6
//n<=10^7;
// find prime number for each query
// if u try to find for prime number using O(sqrt(n))then sqrt(n)*q>1sec

const int N=1e5+9;
int main (){
    vector<int> high_primefactor(N,0);// store high prime factor of ith element
    vector<int> low_primefactor(N,0);// store low prime factor of ith element
    vector<int> v(N,1);// let assume all numbers are prime 
    v[1]=v[0]=0;
    // sleves algorithm 
    for(int i=2;i<N;i++){// time complexity is O(n*log(log(n)))
        if(v[i]==1){
            low_primefactor[i]=i;
            high_primefactor[i]=i;
            for(int j=i*2;j<N;j+=i){
                v[j]=0;
                if(low_primefactor[j]==0){
                    low_primefactor[j]=i;
                }
                high_primefactor[j]=i;
            }
        }
    }
    // int q;
    // cin>>q;
    // while(q--){
    //     int n;
    //     cin>>n;
    //     if(v[n]==1){//o(1)
    //         cout<<"yes"<<endl;
    //     }else{
    //         cout<<"NO"<<endl;
    //     }
    //     }
    unordered_map<int,int>m;
    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        while(num>1){
            int prime_factor=high_primefactor[num];
            while(num % prime_factor==0){
                m[prime_factor]++;
                num/=prime_factor;
            }
        }
    }
    for(auto it :m){
        cout<<it.first<<" "<<it.second<<""<<endl;
    }

}