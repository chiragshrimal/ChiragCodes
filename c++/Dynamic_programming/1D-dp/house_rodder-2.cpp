#include<bits/stdc++.h>
using namespace std;

// do space optimizadtion 
// time  complexity is O(n)
// space copmplexity is o(1)
// here n means index se hai all the questions 
int space_optimization(int l,int h,vector<int>&arr){
    int a=arr[l];
     if(h-l+1==1){
        return a;
    }
    int b=max(arr[l],arr[l+1]);
    if(h-l+1==2){
        return max(arr[l],arr[h]);
    }
    int c=0;
    for(int i=l+2;i<=h;i++){
        c=max(arr[i]+a,b);
        a=b;
        b=c;
    }
    return c;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n==1){
        cout<<arr[0]<<endl;
        return 1;
    }
    if(n==2){
        cout<<max(arr[0],arr[1])<<endl;
        return 2;
    }
    // in the house robber-2 
    // array is circular way m hai 
    cout<<"using space optimization"<<endl;
    int space1=space_optimization(0,n-2,arr);
    int space2=space_optimization(1,n-1,arr);
    cout<<max(space1,space2)<<endl;
}