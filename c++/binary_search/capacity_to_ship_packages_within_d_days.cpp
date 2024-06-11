#include<bits/stdc++.h>
using namespace std;
// time complexity is O(n)
long long int count_days(vector<int>& v,int mid){
    int cnt=0;
    long long int sum=0;
        for(int j=0;j<v.size();j++){
            if((sum+v[j])<=mid){
                sum=sum+v[j];
            }else{
                cnt++;
                sum=v[j];
            }
        }
        if(sum<=mid){
            cnt++;
        }
        return cnt;
}
// brute force apporach 
// time complexity is O()>1 sec
// space complexity is O(1)

int minimum_weight_brute(vector<int>& v,int d){
    int n=v.size();
    int max=0;
    for(int i=0;i<v.size();i++){
        max+=v[i];
    }
    int min=*max_element(v.begin(),v.end());
    int minimum=-1;
    for(int i=max;i>=min;i--){
        int cnt=count_days(v,i);
        if(cnt<=d){
            minimum=i;
        }
    }
    return minimum;
}

// optimal apporach 
// time complexity is O()<1sec
// space complexity is O(1)

int minimum_weight_optimal(vector<int>& v ,int d){
    int low=*max_element(v.begin(),v.end());
    int high=0;
    for(int i=0;i<v.size();i++){
        high+=v[i];
    }
    while(low<=high){
        int mid=low+((high-low)>>1);
        int cnt=count_days(v,mid);
        if(cnt>d){
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
    int d;
    cin>>d;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int brute=minimum_weight_brute(v,d);
    cout<<brute<<endl;

    int optimal=minimum_weight_optimal(v,d);
    cout<<optimal<<endl;
}