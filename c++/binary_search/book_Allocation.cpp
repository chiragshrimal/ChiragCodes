#include<bits/stdc++.h>
using namespace std;

int count_subarray(vector<int>& v,long long int mid,int k){
    int n=v.size();
    int cnt=0;
    long long int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+v[i];
        if(sum==mid){
            sum=0;
            cnt++;
        }else{
            if(sum>mid){
            cnt++;
            sum=v[i];
            }
           
        }
    }
    if(sum<=mid && sum!=0){
        cnt++;
    }
    return cnt;
   }
    int splitArray(vector<int>& v, int k) {
        int n=v.size();
        long long int low=*max_element(v.begin(),v.end());
        long long int high=0;
        for(int i=0;i<n;i++){
            high+=v[i];
        }
        while(low<=high){
            long long int mid=low+((high-low)>>1);
            int p=count_subarray(v, mid,k);
            cout<<low<<endl;
            if(p>k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
    }
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int brute=splitArray(v,m);
    cout<<brute<<endl;
}