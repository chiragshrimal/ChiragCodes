#include<bits/stdc++.h>
using namespace std;
void reverse(int l,int h,int arr[]){
    int i=l;
    int j=h;
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}
void left_rotation(int n,int arr[],int k){
    reverse(0,n-1,arr);
    reverse(0,n-k-1,arr);
    reverse(n-k,n-1,arr);
}
int main (){
    int n;
    cout<<"enter size of array\n";
    cin>>n;
    int arr[n];
    cout<<"enter elements of array\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"enter number of rotation\n";
    cin>>k;
    k=k%n;
    left_rotation(n,arr,k);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }



}