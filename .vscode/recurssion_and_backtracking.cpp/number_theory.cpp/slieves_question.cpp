#include<bits/stdc++.h>
using namespace std;

const int N=3*1e5;

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int mark[N]={0};
    for(int i=0;i<n;i++){
        mark[v[i]]++;
    }
    vector<int> ans(N,0);
    for(int i=2;i<N;i++){
        for(int j=i;j<N;j+=i){
            if(mark[j]!=0){
                ans[i]=ans[i]+mark[j];
            }
        }
    }
    ans[1]=n;
    int t;
    cin>>t;
    while(t--){
        int p,q;
        cin>>p>>q;
        long long int lcm_number=lcm(p,q);
        int result=0;
        if(lcm_number>N){
            result=ans[p]+ans[q];
        }else{
            result=ans[p]+ans[q]-ans[lcm(p,q)];
        }
        cout<<result<<endl;
    }
    return 0;

}