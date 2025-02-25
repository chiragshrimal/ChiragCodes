#include<bits/stdc++.h>
using namespace std;

// optimal apporach 
// time complxxity  is O(3*N)
// spacve complexity is O(3*N)

int river_water(vector<int>& arr){
    int n=arr.size();
    vector<int>left(n,0);
    vector<int> right(n,0);
    left[0]=arr[0];
    right[n-1]=arr[n-1];
    for(int i=1;i<n;i++){
        left[i]=max(left[i-1],arr[i]);
    }
    for(int i=n-2;i>=0;i--){
        right[i]=max(right[i+1],arr[i]);
    }
    int total=0;
    for(int i=0;i<n;i++){
        total=total+min(left[i],right[i])-arr[i];
    }
    return total;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int total=river_water(arr);
    cout<<total;
}