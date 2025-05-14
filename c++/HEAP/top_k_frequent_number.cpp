#include<bits/stdc++.h>
using namespace std;

// brute force apporach 
// time complexity is o(n)+o(nlog(n));
// space complexity is O(n) in merge sort 

vector<int> brute_apporach(vector<int>&arr,int k){
    int n=arr.size();
    vector<int> ans(k,0);
    vector<pair<int,int>> help;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    // for(auto it : m){
    //     cout<<it.first<<" ";
    //     cout<<it.second<<endl;
    // }
    for(auto it : m){
        help.push_back(pair(it.second,it.first));
    }

    // for(auto it : help){
    //     cout<<it.first<<" ";
    //     cout<<it.second<<endl;
    // }
    sort(help.begin(),help.end());

    int z=0;
    for(int i=help.size()-1;i>=help.size()-k;i--){
        ans[z]=help[i].second;
        z++;
    }
    return ans;

}


// optimal apporach 
// time complexity is O()
// ṣpace complexity is O()

vector<int> optimal_apporach(vector<int>&arr,int k){
    int n=arr.size();
    vector<int> ans(k,0);
    vector<pair<int,int>> v;
    unordered_map<int,int> m;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> H;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    for(auto it : m){
        v.push_back(pair(it.second,it.first));
    }
    for(int i=0;i<v.size();i++){
        H.push(v[i]);
        if(H.size()>k){
            H.pop();
        }
    }
    int z=k-1;
    while(H.size()>0){
        ans[z]=H.top().second;
        H.pop();
        z--;
    }
    return ans;

}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n,0);
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    cout<<"using brute apporach"<<endl;
    vector<int> brute=brute_apporach(arr,k);
    for(auto it : brute){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<"using optimal apporach"<<endl;
    vector<int> optimal=optimal_apporach(arr,k);
    for(auto it : optimal){
        cout<<it<<" ";
    }
    cout<<endl;

}