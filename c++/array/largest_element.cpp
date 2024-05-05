#include<bits/stdc++.h>
using namespace std;
int n;
//1. u can sort the array but time complaxity is o(nlog(n)) and space complexity o(1)by quick sort
//2. u can traverse the array time complexity is o(n) and space complexity is o(1)
int remove_duplicate(int n,int arr[]){
    int i=0;
    for(int j=0;j<n-1;j++){
        if(arr[j]!=arr[j+1]){
            arr[i+1]=arr[j+1];
            i++;
        }
    }
    return i+1;

}
bool check_sort(int n,int arr[]){
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }
    return true;
}

int second_largest_element(int n,int arr[]){
int old_largest=INT_MIN;
int new_largest=INT_MIN;
for(int i=0;i<n;i++){
    if(new_largest<arr[i]){
        old_largest=new_largest;
        new_largest=arr[i];
    }else{
        if(old_largest<arr[i] && new_largest!=arr[i]){
            old_largest=arr[i];
        }
    }
}
return old_largest;

}
int largest_element(int n,int arr[]){
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    return max;
}
int main(){
    cout<<"enter size of array\n";
    cin>>n;
    int arr[n];
    cout<<"enter element of array\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max=largest_element(n,arr);
    cout<<"maximum element of array is :";
    cout<<max<<endl;
    int second_largest=second_largest_element( n,arr);
    cout<<"second largest element of array is :";
    cout<<second_largest<<endl;

    bool check=check_sort(n,arr);
    if(check==1){
        cout<<"yes\n";
    }else{
        cout<<"NO\n";
    }
    int m=remove_duplicate(n,arr);
    for(int i=0;i<m;i++){
        cout<<arr[i]<<endl;
    }

    
}