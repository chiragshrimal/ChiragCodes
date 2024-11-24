#include<bits/stdc++.h>
using namespace std;
int find_maximum_sum(vector<int>& v,int k){
    int n=v.size();
    int l=0;
    int r=k-1;
    int sum=0;
    int max=INT_MIN;
    for(int i=l;i<=r;i++){
        sum+=v[i];
    }
    for(int i=0;i<=k;i++){
        if(max<sum){
            max=sum;
        }
        if(l==0){
            l=n-1;
        }else{
            l--;
        }
        sum=sum+v[l];
        sum=sum-v[r];
        r--;
        if(r<0){
            r=n-1;
        }
    }
    return max;
}
int main(){
    int n;
    cin>> n;
    int k;
    cin>>k;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int count=find_maximum_sum(v,k);
    cout<<count<<endl;

}