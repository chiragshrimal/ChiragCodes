#include<bits/stdc++.h>
using namespace std;

// brute force apporach 
// time complexity is o(nlog(n))
// space complexity is O(n);

vector<int> brute_apporach(vector<int>&arr,int k,int x){
    int n=arr.size();
    vector<int> ans(k,0);
    vector<pair<int,int>> make;
    for(int i=0;i<n;i++){
        make.push_back(pair(abs(arr[i]-x),arr[i]));
    }
    sort(make.begin(),make.end());
    for(int i=1;i<=k;i++){
        ans[i-1]=make[i].second;
    }
    return ans;
}

// optimal apporach 
// timr complexity is O(nlog(k))
// ṣpace complexity is O(k)

vector<int> optimal_apporach(vector<int>&arr,int k,int x){
    // because niche main m phle hi bdake diya hai 
    int n=arr.size();
    // heap m automatically pair ki first value se sort ho jayegi 
    priority_queue<pair<int,int>> H;

    for(int i=0;i<n;i++){
        H.push(pair(abs(arr[i]-x),arr[i]));
        if(H.size()>k+1){
            H.pop();
        }
    }
    vector<int> ans(k,0);
    int z=k-1;
    while(H.size()>0){
        ans[z]=H.top().second;
        H.pop();
        z--;
    }

    for(auto it : ans){
        cout<<it<<endl;
    }
    return ans;

}

int main(){
    int n,k,x;
    cin>>n>>k>>x;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>optimal=optimal_apporach(arr,k,x);
    cout<<"using optimal apporach"<<endl;
    for(int i=0;i<k;i++){
        cout<<optimal[i]<<" ";
    }
    cout<<endl;
    vector<int>brute=brute_apporach(arr,k,x);
    cout<<"using brute apporach"<<endl;
    for(int i=0;i<k;i++){
        cout<<brute[i]<<" ";
    }
}