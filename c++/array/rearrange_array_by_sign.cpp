#include<bits/stdc++.h>
using namespace std;
// brute force apporach 
// time complexity is O(n)
// space complexity is O(n)
void rearrange_brute(int n,int arr[]){
    int posi[n/2];
    int negi[n/2];
    int k=0;
    int l=0;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            negi[l]=arr[i];
            l++;
        }
        if(arr[i]>=0){
            posi[k]=arr[i];
            k++;
        }
    }
    for(int i=0;i<n/2;i++){
        arr[2*i]=posi[i];
        arr[2*i+1]=negi[i];
    }

    return ;
}
// optimal apporach 
//time complexity is o(n) but brute ke respect m only ek hi iteration lgegi
// space complexity is O(n)

int * rearrange_optimal(int n,int arr[]){
    int *temp=(int*)malloc(n*sizeof(int));
    if(n==1){
        temp[0]=arr[0];
    }
    if(n==2){
        temp[0]=min(arr[0],arr[1]);
        temp[1]=max(arr[0],arr[1]);
    }
    int possi=0;
    int neggi=1;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            temp[possi]=arr[i];
            possi+=2;
        }else{
            temp[neggi]=arr[i];
            neggi+=2;
        }
    }
    return temp;
}
// if number of positive not equal to negative 
// time complexity is o(2n)
// space complexity is o(n)
void rearrange_not_equal(int n,int arr[]){
    int possi[n];
    int neggi[n];
    int k=0;
    int l=0;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            possi[k]=arr[i];
            k++;
        }else{
            neggi[l]=arr[i];
            l++;
        }
    }
    if(k>l){
        for(int i=0;i<l;i++){
            arr[2*i]=possi[i];
            arr[2*i+1]=neggi[i];
        }
        int index=2*l;
        for(int i=l;i<k;i++){
            arr[index]=possi[i];
            index++;
        }
    }else{
        for(int i=0;i<k;i++){
            arr[2*i]=possi[i];
            arr[2*i+1]=neggi[i];
        }
        int index=2*k;
        for(int i=k;i<l;i++){
            arr[index]=neggi[i];
            index++;
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // rearrange_brute(n,arr);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<endl;
    // }
    // int *temp=rearrange_optimal(n,arr);
    // for(int i=0;i<n;i++){
    //     cout<<temp[i]<<endl;
    // }
    rearrange_not_equal(n,arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}