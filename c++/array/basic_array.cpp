#include<bits/stdc++.h>
using namespace std;
// int  arr[10]---> all value are 0;
    // if we deffine arrays as global  then maximum size we can diffine is 1e7
int main(){
    // int arr[10] -->> garbage vaue aqre there 
    // if we deffine arrays in the main function then maximum size we can diffine is 1e6
    int arr[5];
    printf("enter %d number\n",5);
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
    for(int i=0;i<5;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}