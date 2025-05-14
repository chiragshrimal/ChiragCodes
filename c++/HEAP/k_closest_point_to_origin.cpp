#include<bits/stdc++.h>
using namespace std;

// brute force apporach
// time complexity is O()
// space complexity is O()

bool compare(vector<int>&v1 , vector<int>&v2){
    return (v1[0]*v1[0]+v1[1]*v1[1])<(v2[0]*v2[0]+v2[1]*v2[1]);
}

vector<pair<int,int>> brute_apporach(vector<vector<int>>& arr, int k){
    int n=arr.size();
    sort(arr.begin(),arr.end(),compare);
    vector<pair<int,int>> ans;
    for(int i=0;i<k;i++){
        ans.push_back(pair(arr[i][0],arr[i][1]));
    }
    return ans;
}


// optimal apporach 
// time complexity is o()
// space complexity is o()

vector<pair<int,int>> optimal_apporach(vector<vector<int>>&arr, int k){
    int n=arr.size();
    vector<pair<int,int>> ans;
    priority_queue<pair<int,pair<int,int>>> H;
    for(int i=0;i<n;i++){
        int k=arr[i][0]*arr[i][0]+arr[i][1]*arr[i][1];
        H.push(pair(k,pair(arr[i][0],arr[i][1])));
        if(H.size()>k){
            H.pop();
        }
    }
    while(H.size()>0){
        ans.push_back(H.top().second);
        H.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> arr(n,vector<int>(2,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"using brute apporach "<<endl;
    vector<pair<int,int>> brute=brute_apporach(arr,k);
    for(int i=0;i<k;i++){
        cout<<brute[i].first<<" ";
        cout<<brute[i].second<<" ";
        cout<<endl;
    }
    cout<<"using optimal apporach "<<endl;
    vector<pair<int,int>> optimal = optimal_apporach(arr,k);
    for(int i=0;i<k;i++){
        cout<<optimal[i].first<<" ";
        cout<<optimal[i].second<<" ";
        cout<<endl;
    }
}