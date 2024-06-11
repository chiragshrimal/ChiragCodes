#include<bits/stdc++.h>
using namespace std;
// itrative apporach 
// time complexity is O(log(n))
// space complexity is O(1);
int binary_search_itrative(vector<int>& v,int n,int target){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+((high-low)>>1);
        if(target==v[mid]){
            return mid;
        }
        if(target<v[mid]){
            high=mid-1;
        }else{
            low=mid+1;
        }

    }
    return -1;
}

// recursive apporach 
// time complexity is O(log(n))
// space complecity is O(log(n));
int binary_search_recursive(int low,int high,vector<int>& v,int target){
    if(low>high){
        return -1;
    }
    int mid=low+((high-low)>>1);
    if(target==v[mid]){
        return mid;
    }
    if(target<v[mid]){
        return binary_search_recursive(low,mid-1,v,target);
    }
    return binary_search_recursive(mid+1,high,v,target);

}


int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int index=binary_search_itrative(v,n,target);
    if(index==-1){
        cout<<"not found"<<endl;
    }else{
        cout<<v[index]<<endl;
    }
    int index2=binary_search_recursive(0,n-1,v,target);
    if(index2==-1){
        cout<<"not found"<<endl;
    }else{
        cout<<v[index2]<<endl;
    }
}