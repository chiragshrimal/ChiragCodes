#include<bits/stdc++.h>
using namespace std;

bool ispossible(vector<int>& v,int d,int c){
    int cnt=1;
    int last=v[0];
    for(int i=1;i<v.size();i++){
        if((v[i]-last)>=d){
            cnt++;
            last=v[i];
        }
    }
    if(cnt>=c){
        return true;
    }else{
        return false;
    }
}
// brute force apporach 
// time complexity is O(n^2)>1sec
// space complexity is O(1)

int Aggresive_cows_brute(vector<int>& v,int c){
    sort(v.begin(),v.end());
    int n=v.size();
    for(int i=1;i<=(v[n-1]-v[0]);i++){
        if(ispossible(v,i,c)==false){
            return i-1;
        }
    }
}

// optimal apporach 
// time complexity is O()
// space complexity is O()

int Aggresive_cows_optimal(vector<int>& v,int c){
    sort(v.begin(),v.end());
    int n=v.size();
    int low=1;
    int high=v[n-1]-v[0];
    while(low<=high){
        int mid=low+((high-low)>>1);
        if(ispossible(v,mid,c)==true){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return high;
}

int main(){
    int n;
    cin>>n;
    int c;
    cin>>c;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int brute=Aggresive_cows_brute(v,c);
    cout<<brute<<endl;

    int optimal=Aggresive_cows_optimal(v,c);
    cout<<optimal<<endl;
}