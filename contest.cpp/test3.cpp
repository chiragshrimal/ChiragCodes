#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n,0);
        if(n%2==0){
            if(n>=2){
                arr[0]=1;
                arr[1]=2;
            }
            int i=n-1;
            int flag=1;
            int j=2;
            int h=3;
            while(j<=i){
                if(flag==1){
                    arr[i]=h;
                    flag=0;
                    h++;
                    i--;
                }else{
                    arr[j]=h;
                    flag=1;
                    h++;
                    j++;
                }
            }
        }else{
            if(n>=2){
                arr[0]=2;
                arr[1]=1;
            }
            for(int i=2;i<n;i++){
                arr[i]=i+1;
            }
        }
        int k=0;
        int flag=1;
        for(int i=0;i<n;i++){
            if(flag==1){
                k=k&arr[i];
                flag=0;
            }else{
                k=k|arr[i];
                flag=1;
            }
        }
        cout<<k<<endl;

    }


}