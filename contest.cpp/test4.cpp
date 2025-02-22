#include<bits/stdc++.h>
using namespace std;

long long int m=1e9+7;
int solve(vector<int>& arr){
    int n=arr.size();
    if(n==1){
        return arr[0];
    }
    int mini=INT_MAX;
    int mini_index=-1;
    int maxi=INT_MIN;
    int maxi_index=-1;
    for(int i=0;i<n;i++){
        if(mini>arr[i] && arr[i]%2==0){
            mini=arr[i];
            mini_index=i;
        }
        if(maxi<arr[i]){
            maxi=arr[i];
            maxi_index=i;
        }
    }
    long long int sum=0;
    for(int i=0;i<n;i++){
        if(i!=mini_index && i!=maxi_index){
            sum+=arr[i];
        }
    }
    if(mini_index!=maxi_index)
    sum=sum+mini/2 + maxi*2;
    return sum;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int> ans(n,0);
          vector<int> temp;
        for(int i=0;i<n;i++){
          
            temp.push_back(arr[i]);
            ans[i]=solve(temp);
        }

        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

    }
}