#include<bits/stdc++.h>
using namespace std;

// lower bound means v[i]>=target
// i---> will be smalest 


// itrative apporach 
// time complexity is O(log(n))
// space complexity is O(1);
int binary_search_itrative(vector<int>& v,int n,int target){
    int low=0;
    int high=n-1;
    int index=INT_MAX;
    while(low<=high){
        int mid=low+((high-low)>>1);
        if(target<=v[mid]){
            index=min(index,mid);
            high=mid-1;
        }else{
            low=mid+1;
        }

    }
    return index;
}

// recursive apporach 
// time complexity is O(log(n))
// space complecity is O(log(n));
void binary_search_recursive(int low,int high,vector<int>& v,int target,int*index){
    if(low>high){
        return ;
    }
    int mid=low+((high-low)>>1);
    if(target<=v[mid]){
        *index=min(*index,mid);
        binary_search_recursive(low,mid-1,v,target,index);
    }else{
        binary_search_recursive(mid+1,high,v,target,index);
    } 

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
    if(index==INT_MAX){
        cout<<v.size()<<endl;
    }else{
        cout<<index<<endl;
    }
    int index2=INT_MAX;
    binary_search_recursive(0,n-1,v,target,&index2);
    if(index2==INT_MAX){
        cout<<v.size()<<endl;
    }else{
        cout<<index2<<endl;
    }
}