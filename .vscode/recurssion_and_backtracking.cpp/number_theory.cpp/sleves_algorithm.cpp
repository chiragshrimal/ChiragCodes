#include<bits/stdc++.h>
using namespace std;
//q<=10^6
//n<=10^7;
// find prime number for each query
const int N=1e5+9;
int main (){
    vector<int> high_primefactor(N,0);
    vector<int> low_primefactor(N,0);
    vector<int> v(N,0);
    for(int i=2;i<=N;i++){// time complexity is O(n*log(log(n)))
        if(v[i]==0){
            low_primefactor[i]=i;
            high_primefactor[i]=i;
            v[i]=1;
            for(int j=i*2;j<=N;j+=i){
                v[j]=-1;
                if(low_primefactor[j]==0){
                    low_primefactor[j]=i;
                }
                high_primefactor[j]=i;
            }
        }
    }
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        if(n==1){
            cout<<"no"<<endl;
        }else{
        if(v[n]==1){
            cout<<"yes"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        }
    }
}