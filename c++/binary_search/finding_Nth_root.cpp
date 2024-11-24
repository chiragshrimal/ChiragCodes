#include<bits/stdc++.h>
using namespace std;

// time complexity is O(log(b))
int f(int mid,int n,int m){
    long long int ans=1;
    for(int i=1;i<=n;i++){
        ans=ans*mid;
        if(ans>m){
            return 1;
        }
    }
    if(ans==m){
        return 0;
    }else{
        return -1;
    }
}
// brute force apporach
// time complexity is O(m*log(*n));
// space complexity is O(1);
int finding_nth_root_brute(int n,int m){
    for(int i=1;i<=m;i++){
        int k=f(i,n,m);
        if(k==0){
            return i;
        }else{
            if(k==1){
                return -1;
            }
        }
    }
}

// iterative apporach 
// time complexity is O(log(m)*log(n));
// space complexity is O(1);

int finding_nth_root_iterative(int n,int m){
    int low=1;
    int high=m;
    while(low<=high){
        long long int mid=low+((high-low)>>1);
        long long int k=f(mid,n,m);
        if(k==0){
            return mid;
        }
        if(k==1){
            high=mid-1;
        }else{
            low=low+1;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    int brute=finding_nth_root_brute(n,m);
    cout<<brute<<endl;

    int optimal=finding_nth_root_iterative(n,m);
    cout<<optimal<<endl;
}