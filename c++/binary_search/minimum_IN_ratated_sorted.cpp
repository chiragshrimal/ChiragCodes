#include<bits/stdc++.h>
using namespace std;
// iterative apporach 
// time complexity is O(log(n))
// space complexity is O(1);

int Minimum_element_iterative(vector<int>& v,int n){
    int low=0;
    int high=n-1;
    int ans=INT_MAX;
    while(low<=high){
        int mid=low+((high-low)>>1);
        if(v[low]<v[mid]){
            ans=min(ans,v[low]);
            low=mid+1;
        }else{
            ans=min(ans,v[mid]);
            high=mid-1;
            }
        }
        return ans;
    }
    // more optimize with more conditions 
    // time complexity is O(log(n))
    // space complexity is O(1);
int Minimum_element_iterative2(vector<int>& v,int n){
    if(n==1){
        return v[0];
    }
    int low=0;
    int high=n-1;
    int ans=INT_MAX;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(v[low]<v[mid] && v[mid]<v[high]){
            return v[low];
        }
        if(v[low]<v[mid]){
            ans=min(ans,v[low]);
            low=mid+1;
        }else{
            ans=min(ans,v[mid]);
            high=mid-1;
        }
    }
    return ans;
}    
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int min_element=Minimum_element_iterative(v,n);
    cout<<min_element<<endl;
}