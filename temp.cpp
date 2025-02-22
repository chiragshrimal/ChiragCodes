#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y,k;
        cin>>x>>y>>k;
        if(k<=x  && k<=y){
            cout<<0<<" ";
            cout<<0<<" ";
            cout<<0<<" ";
            cout<<y<<" ";
            cout<<endl;
            cout<<0<<" ";
            cout<<0<<" ";
            cout<<x<<" ";
            cout<<0<<" ";
            cout<<endl;
            continue;
        }
        if((k>=x && k<=y )|| (k<=x && k>=y) || (k>x && k>y)){
            int mini=min(x,y);
            int maxi=max(x,y);
            cout<<0<<" ";
            cout<<0<<" ";
            cout<<mini<<" ";
            cout<<mini<<" ";
            cout<<endl;
            cout<<0<<" ";
            cout<<mini<<" ";
            cout<<mini<<" ";
            cout<<0<<" ";
            cout<<endl;
            continue;
        }
    }
}