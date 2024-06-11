#include<bits/stdc++.h>
using namespace std;

// brute force apporach 
// time complexity is o(n);
// space complexity is O(1)

int find_squrt(int n){
    int ans=-1;
    for(int i=1;i<=n;i++){
        if(i*i<=n){
            ans=i;
        }else{
            break;
        }
    }
    return ans;
}

// iterative apporach 
// time complexity is O(log(n))
// space complecity is O(1)

int find_squrt_iterative(int n){
    int low=1;
    int high=n;
    int ans=-1;
    while(low<=high){
        int mid=low+((high-low)>>1);
        if(mid*mid==n){
            return mid;
        }
        if(mid*mid>n){
            high=mid-1;
        }else{
            ans=mid;
            low=mid+1;
        }

    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int brute=find_squrt(n);
    cout<<brute<<endl;
    int optimal=find_squrt_iterative(n);
    cout<<optimal<<endl;
}