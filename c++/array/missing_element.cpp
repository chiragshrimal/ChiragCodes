#include<bits/stdc++.h>
using namespace std;

// better apporach 
// time complexity is o(n)
// space complexity is o(n)
int find_missing(int n,int arr[]){
    int index[n+1];
    for(int i=0;i<n+1;i++){
        index[i]=0;
    }
    for(int i=0;i<n-1;i++){
        index[arr[i]]=1;
    }
    for(int i=1;i<n+1;i++){
        if(index[i]==0){
            return i;
        }
    }
    return -1;

}
// optimal apporach 
//time complexity is o(n)
// space complexity is o(1)
  long long int find_missing_optimal(int n,int arr[]){
     long long int sum=(n*(n+1))/2;
     long long int arraysum=0;
    for(int i=0;i<n-1;i++){
        arraysum+=arr[i];
    }
    long long int difference =sum-arraysum;
    return difference;


}
int find_missing_using_XOR(int n,int arr[]){
    int xor1=0;
    int xor2=0;
    for(int i=0;i<n-1;i++){
        xor2^=arr[i];
        xor1^=(i+1);
    }
    xor1=xor1^n;
    return xor1^xor2;

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    int missing=find_missing(n,arr);
    cout<<"missing element is:\n";
    cout<<missing<<endl;
    long long int optimal_missing =find_missing_optimal(n,arr);
    cout<<"missing element is:\n";
    cout<<optimal_missing<<endl;

    int using_xor=find_missing_using_XOR(n,arr);
     cout<<"missing element is:\n";
    cout<<using_xor<<endl;
}  