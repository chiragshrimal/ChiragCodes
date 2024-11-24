#include<bits/stdc++.h>
using namespace std;

// iterative apporach 
// time complexity is O(log(n))
// space complexity is O(1)

int single_element_iterative(vector<int>& v,int n){
    if(n==1){
        return v[0];
    }
    // check for last element 
    if(v[n-1]!=v[n-2]){
        return v[n-1];
    }
    // check for first element 
    if(v[0]!=v[1]){
        return v[0];
    }
    int low=2;
    int high=n-3;
    while(low<=high){
        int mid=low +(high-low)/2;
        if(v[mid]!=v[mid-1] && v[mid]!=v[mid+1]){
            return v[mid];
        }

        if(v[mid]==v[mid-1]){
            if(((mid-low+1)%2)!=0){
                high=mid;
            }else{
                low=mid+1;
            }
        }else{
            if(((high-mid+1)%2)!=0){
                low=mid;
            }else{
                high=mid-1;
            }
        }
        
    }
    return -1;
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
    int element =single_element_iterative(v,n);
    cout<<element<<endl;
}