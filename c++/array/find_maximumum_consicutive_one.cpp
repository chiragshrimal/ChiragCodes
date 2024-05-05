#include<bits/stdc++.h>
using namespace std;
int maximum_consecutive_ones(int n,int arr[]){
    int old_max=0;
    int new_max=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            new_max++;
        }else{
            if(old_max<new_max){
                old_max=new_max;
                new_max=0;
            }
        }
    }
    return old_max;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    int max=maximum_consecutive_ones(n,arr);
    cout<<"maximum number of consecative 1's is :"<<endl;
    cout<<max<<endl;

}