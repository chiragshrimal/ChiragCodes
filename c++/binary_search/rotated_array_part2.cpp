#include<bits/stdc++.h>
using namespace std;
// iterative apporach 
// time complexity is O(log(n))
// space complexity is O(1);

int find_element_iterative(vector<int>& v,int n ,int target){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+((high-low)>>1);
        if(v[mid]==target){
            return mid;
        }
        if(v[mid]==v[low] && v[mid]==v[high]){
            high=high-1;
            low=low+1;
        }else{
        if(v[low]<=v[mid]){
            if(target>=v[low] && target<v[mid] ){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }else{
            if(v[mid]<=v[high]){
                if(target>v[mid] && target<=v[high]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }

    }
    }
    return -1;
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
    int index=find_element_iterative(v,n,target);
    cout<<index<<endl;
}