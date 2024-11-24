#include<bits/stdc++.h>
using namespace std;

//check palindrom or not
bool is_palindrom(int arr[],int l,int h){
    if(l>=h){
        return true;
    }else{
        if(arr[l]==arr[h]){
            return is_palindrom(arr,l+1,h-1);
        }else{
            return false;
        }
    }
}

void f(int arr[],int l,int h){
    if(l>=h){
        return;
    }
    else{
        swap(arr[l],arr[h]);
        f(arr,l+1,h-1);
    }
}
int main(){
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    int  arr[n];
    cout<<"enter numbers"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    f(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }

    bool palindrom=is_palindrom(arr,0,n-1);
    cout<<palindrom<<endl;

}