#include<bits/stdc++.h>
using namespace std;
// brute force apporach 
// time complexity is O(n)
// space complexity is O(1)
int findKthPositive_brute(vector<int>& v, int k) {
        int n=v.size();
        if((v[n-1]-n)<k){
            int diff=k-(v[n-1]-n);
            return v[n-1]+diff;
        }
        int h=0;
        int cnt=0;
        for(int i=1;i<=v[n-1];i++){
            if(v[h]!=i){
                cnt++;
                if(cnt==k){
                    return i;
                }
            }else{
                h++;
            }
        }
        return -1;
    }

// if n is very large than O(n) not work;
// oprimal apporach 
// time complexity is O(log(n))
// space complexity is O(1);

int findKthPositive_optimal(vector<int>& v,int k){
    // out side the search space 
    int n=v.size();
    if((v[n-1]-n)<k){
            int diff=k-(v[n-1]-n);
            return v[n-1]+diff;
        }
        if(k<v[0]){
            return k;
        }
    // search space     
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+((high-low)>>1);
        if((v[mid]-mid-1)>=k){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    int diff=v[high]-high-1;
    return v[high]+(k-diff);
}

int  main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int brute=findKthPositive_brute(v,k);
    cout<<brute<<endl;

    int optimal=findKthPositive_optimal(v,k);
    cout<<optimal<<endl;
}