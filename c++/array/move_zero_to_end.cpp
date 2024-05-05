#include<bits/stdc++.h>
using namespace std;

void move_zero(int n,int arr[]){
    int i=0;
    while(arr[i]!=0){
        i++;
    }
    int j=i+1;
    while(j<n){
        while(arr[j]==0){
            j++;
        }
        if(j<n){
            swap(arr[i],arr[j]);
            i++;
        }
    }

}

int main(){
    int n;
    cout<<"enter a number\n";
    cin>>n;
    int arr[n];
    cout<<"enter elements of array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    move_zero(n,arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}