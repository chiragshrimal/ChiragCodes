#include<bits/stdc++.h>
using namespace std;

const int N=1e6;

int main(){
    cout<<"hello"<<endl;
    int n;
    cin>>n;
    cout<<n<<endl;
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
    int t;
    cin>>t;
    cout<<t<<endl;
    while(t--){
        int p,q;
        cin>>p>>q;
        cout<<p<<q<<endl;
        int result=ans[p]+ans[q]-ans[gcd(p,q)];
        cout<<result<<endl;
    }
    return 0;

}