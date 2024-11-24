#include<bits/stdc++.h>
using namespace std;
int main(){
        int n;
        cin>>n;
        int k=1;
        for(int i=1;i<=2*n-1;i++){
            for(int j=1;j<=2*n-1;j++){
                if(i==k||j==k||i==n-k+1||j==n-k+1){
                    cout<<n-k+1;
                }
            }
    }
    }