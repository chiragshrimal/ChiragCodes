#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        vector<int> check(n+1,0);
        check[v[0]]=1;
        int cnt=0;
        if(n==1){
            cnt++;
            cout<<"yes"<<endl;
            continue;
        }
        for(int i=1;i<n;i++){
            if( ((v[i]-1>0) && check[v[i]-1]==1)  || (((v[i]+1<=n) && check[v[i]+1]==1))){
                check[v[i]]=1;
            }else{
                cnt++;
                cout<<"no"<<endl;
                break;
            }
           
        }
        if(cnt==0){
            cout<<"yes"<<endl;
        }
    }

}