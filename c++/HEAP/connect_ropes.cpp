#include<bits/stdc++.h>
using namespace std;

// brute force apporach 
// time complexity is O(n*nlog(n))
// space complexity is O(n)

int brute_apporach(vector<int>&arr){
    int cost=0;
    while(arr.size()>=2){
        sort(arr.begin(),arr.end());
        int c1=arr[0];
        int c2=arr[1];
        cost=cost+c1+c2;
        arr.erase(arr.begin());
        arr.erase(arr.begin());
        arr.push_back(c1+c2);
    }
    return cost;
}

// optimal apporach 
// time compleity is O()
// space compleity is O()

int optimal_apporach(vector<int> &arr){
    int n=arr.size();
    int cost=0;
    priority_queue<int,vector<int>,greater<int>> H; 
    for(int i=0;i<n;i++){
        H.push(arr[i]);
    }
    while(H.size()>=2){
        int f1=H.top();
        H.pop();
        int f2=H.top();
        H.pop();
        cost=cost+f1+f2;
        H.push(f1+f2);
    }
    return cost;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // both apporaches ko independently run krna pdegA 
    // because hum ek hi array m change kar rhe hai 
    // cout<<"using brute apporach"<<endl;
    // int brute=brute_apporach(arr);
    // cout<<brute<<endl;
    cout<<"using optimal apporach "<<endl;
    int optimal=optimal_apporach(arr);
    cout<<optimal<<endl;
}