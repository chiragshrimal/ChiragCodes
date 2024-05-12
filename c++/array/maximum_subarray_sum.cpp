#include<bits/stdc++.h>
using namespace std;

// brute force apporach 
// time complexity is O(n^3)
// space complexity is O(1)
int subarray_maximum_brute(int n,int arr[]){
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<j;k++){
                sum+=arr[k];
            }
            if(max<sum){
                max=sum;
            }
        }
    }
    if(max<0){
        return 0;
    }
    return max;
}


// better  apporach 
// time complexity is O(n^2)
// space complexity is O(1)
int subarray_maximum_better(int n,int arr[]){
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(max<sum){
                max=sum;
            }
        }
    }
    if(max<0){
        return 0;
    }
    return max;
}

// optimal apporach 
// time complexity is o(n)
// space complexity is  O(1)

int subarray_maximum_optimal(int n,int arr[]){
    int max=INT_MIN;
    int sum=0;
    int ansstart=-1;
    int anslast=-1;
    int start=-1;
    for(int i=0;i<n;i++){
        if(sum<=0){
            start=i;
        }
        if(max<sum){
            max=sum;
            anslast=i;
            ansstart=start;
        }
        if(sum<0){
            sum=0;
        }
        sum+=arr[i];
    }
    cout<<"subarray is :"<<endl;
    for(int i=ansstart;i<anslast;i++){
        cout<<arr[i]<<endl;
    }
    cout<<endl;
    if(max<0){
        return 0;
    }
    return max;

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int brute=subarray_maximum_brute(n,arr);
    cout<<brute<<endl;

    int better=subarray_maximum_better(n,arr);
    cout<<better<<endl;

    int optimal=subarray_maximum_optimal(n,arr);
    cout<<optimal<<endl;
}