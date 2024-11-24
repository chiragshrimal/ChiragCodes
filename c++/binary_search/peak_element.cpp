#include<bits/stdc++.h>
using namespace std;
// iterative apporach 
// time complexity is O(log(n))
// space complexity is O(1);
int find_peak_iterative(vector<int> & v){
       int n=v.size();
        int low=0;
        int high=n-1;
        if(n==1){
            return low;
        }
        if(v[low]>v[low+1]){
            return low;
        }
        if(v[high]>v[high-1]){
            return high;
        }
        while(low<=high){
            int mid=low+((high-low)>>1);
            if(v[mid]>v[mid-1] && v[mid]>v[mid+1]){
                return mid;
            }
            if(v[mid]<v[mid+1]){
                low=mid;
            }else{
                high=mid;
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
    int index=find_peak_iterative(v);
    cout<<v[index]<<endl;
}       