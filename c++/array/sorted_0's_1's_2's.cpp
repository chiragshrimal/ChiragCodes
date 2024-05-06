#include<bits/stdc++.h>
using namespace std;
// brute force apporach 
// just sorted
// time complexity is O(nlog(n))
// space somplexity is O(1)
//
//
//
//
/// better apporach , count number of zeroes and number of 1's 
// number of iteration is more 
// time complexiity is O(n)
// space complexity is O(1)
void sort_better(int n,int arr[]){
    int count0=0;
    int count1=0;
    int count2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            count0++;
        }
        if(arr[i]==1){
            count1++;
        }
    }
    count2=n-count0-count1;
    for(int i=0;i<count0;i++){
        arr[i]=0;
    }
    for(int i=count0;i<count0+count1;i++){
        arr[i]=1;
    }
    for(int i=count0+count1;i<n;i++){
        arr[i]=2;
    }
    return ;
}
// optimal apporach 
// number of iteration is less compair to better apporach 
// time complexity is O(n)
// space complexity is O(1)
void sort_optimal(int n,int arr[]){
    int low=0;
    int high =n-1;
    int mid=0;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }
        if(arr[mid]==1){
            mid++;
        }
        if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    return ;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // sort_better(n,arr);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<endl;
    // }
    sort_optimal(n,arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }

}