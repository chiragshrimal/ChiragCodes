#include<bits/stdc++.h>
using namespace std;
int main (){
    //in c++ we have inbuilt sort 
    //in c++ we have trisort;(quick sort,insertion sort,heap sort);
    //it takes first argument as addres of first element and second argument is addres of next of last element;
    //time complexity O(n*log(n));
    //very very import role inm compitative programming m
    //kuch inbuilt cmp bhi hote hai if u want u can use;
    int n;
    cin>>n;
    int arr[n];
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}