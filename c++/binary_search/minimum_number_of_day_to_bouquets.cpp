#include<bits/stdc++.h>
using namespace std;

// time complexity is O(n)
int count_bouquets(vector<int>& v,int d,int k){
    int cnt=0;
    int b=0;
    for(int i=0;i<v.size();i++){
        if(v[i]<=d){
            cnt++;
        }else{
            b+=(cnt/k);
            cnt=0;
        }
    }
    b=b+(cnt/k);
    return b;
}
// brute force apporach 
// time complexity is O()>1sec
// space complexity is O(1);
int minimum_days_brute(vector<int>& v,int m,int k){
    int minimum=-1;
    if(m*k>v.size()){
        return minimum;
    }
    int max=*max_element(v.begin(),v.end());
    int min=*min_element(v.begin(),v.end());
    for(int i=max;i>=min;i--){
        if(count_bouquets(v,i,k)==m){
            minimum=i;
        }
    }
    return minimum;
}

// optimal apporach 
// time complexity is O()<1sec
// space complexity is O(1)

int  minimum_days_optimal(vector<int>& v,int m,int k){
    int low=*min_element(v.begin(),v.end());
    int high=*max_element(v.begin(),v.end());
    while(low<=high){
        int mid=low + ((high-low)>>1);
        if(count_bouquets(v,mid,k)>=m){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return low;
}
int main(){
    int n;
    cin>>n;
    int m;// number of buquets 
    cin>>m;
    int k;// number of adjecent flower
    cin>>k;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int brute=minimum_days_brute(v,m,k);
    cout<<brute<<endl;

    int optimal=minimum_days_optimal(v,m,k);
    cout<<optimal<<endl;
}