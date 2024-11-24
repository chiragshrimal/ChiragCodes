#include<bits/stdc++.h>
using namespace std; 
  int findMax(vector<int> & v){
    int maxi=INT_MIN;
    int n=v.size();
    for(int i=0;i<n;i++){
        maxi=max(maxi,v[i]);
    }
    return maxi;
}
long long int sum(vector<int>& v,int mid){
        int n=v.size();
        long long int ans=0;
        for(int i=0;i<n;i++){
            ans=ans+(ceil((double)v[i] / (double)mid));
        }
        return ans;
    }
    int f(vector<int>& v,int h){
        int low=1;
        int high=findMax(v);
        int minimum=INT_MAX;
        while(low<=high){
            int mid=low+((high-low)>>1);
            long long int x=sum(v,mid);
            if(x<=h){
                high=mid-1;
                minimum=min(minimum,mid);
            }else{
                low=mid+1;
            }
        }
        return minimum;
    }
    int minEatingSpeed(vector<int>& v, int h) {
        int maxelement=*max_element(v.begin(),v.end());
        int k=f(v,h);
        return k;
    }
int main(){
    int n;
    cin>>n;
    int h;
    cin>>h;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int k=minEatingSpeed(v,h);
    cout<<k<<endl;
}    