#include<bits/stdc++.h>
using namespace std ;

vector<int> NSE_right(vector<int>& arr){
    int n=arr.size();
    stack<int> s;
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        int flag=0;
        while(!s.empty()){
            if(arr[s.top()]<arr[i]){
                ans.push_back(s.top());
                flag=1;
                break;
            }else{
                s.pop();
            }
        }
        if(flag==0){
            ans.push_back(n);
        }
        s.push(i);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

vector<int> NSEE_left(vector<int>& arr){
    int n=arr.size();
    vector<int> ans;
    stack<int> s;
    for(int i=0;i<n;i++){
        int flag=0;
        while(!s.empty()){
            if(arr[s.top()]<=arr[i]){
                ans.push_back(s.top());
                flag=1;
                break;
            }else{
                s.pop();
            }
        }
        if(flag==0){
            ans.push_back(-1);
        }
        s.push(i);
    }
    return ans;
}

int sum_subarray_minimum(vector<int>& arr){
    int n=arr.size();
    long long int m=1e9+7;
    vector<int> left=NSEE_left(arr);
    vector<int> right=NSE_right(arr);
    long long int sum=0;
    for(int i=0;i<n;i++){
        sum=(sum + ((i-left[i])*1ll*(right[i]-i)*arr[i])%m)%m;
    }
    return sum;

}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    long long int sum=sum_subarray_minimum(arr);
    cout<<sum<<endl;
}