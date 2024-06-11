#include<bits/stdc++.h>
using namespace std;

// brute force apporach 
// time complexity is O()>1sec;
// space complexity is O(1);
int minimum_Divisor_brute(vector<int>& v,int thres ){
    int n=v.size();
    int max=*max_element(v.begin(),v.end());
    for(int i=1;i<=max;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum=sum+ceil((double)v[j]/(double)i);
        }
        if(sum<=thres){
            return i;
        }
    }
}
// optimal apporach 
// time complexity is O()<1sec
// space complexity is O(1)

int minimum_Divisor_optimal(vector<int>& v,int thres){
    int low=1;
    int high=*max_element(v.begin(),v.end());
    while(low<=high){
        int mid=low +((high-low)>>1);
        long long int sum=0;
        for(int i=0;i<v.size();i++){
            sum=sum+ceil((double)v[i]/(double)mid);
        }
        if(sum>thres){
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
    int thres;
    cin>>thres;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int brute=minimum_Divisor_brute(v,thres);
    cout<<brute<<endl;

    int optimal=minimum_Divisor_optimal(v,thres);
    cout<<optimal<<endl;
}