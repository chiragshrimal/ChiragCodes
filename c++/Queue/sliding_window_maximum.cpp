#include<bits/stdc++.h>
using namespace std;

int find_max(vector<int>& arr, int s,int f){
    int maxi=INT_MIN;
    for(int i=s;i<=f;i++){
        maxi=max(maxi,arr[i]);
    }
    return maxi;
}

// brute force apporach 
// time cpmlexity is O((n-k+1)*n)
// space complexity is O(n)

vector<int> sliding_window_maximum_brute(vector<int>& arr ,int k){
    vector<int> ans;
    int n=arr.size();
    int maxi=INT_MIN;
    for(int i=0;i<k;i++){
        maxi=max(maxi,arr[i]);
    }
    ans.push_back(maxi);
    int s=1,f=k;
    for(int i=1;i<=n-k+1;i++){
        maxi=max(maxi,find_max(arr,s,f));
        ans.push_back(maxi);
        s++;
        f++;
    }
    return ans;

}

// optimal apporach 
// time complexity is O(2*n)
// space complexity is O(n)

vector<int> sliding_window_maximum_optimal(vector<int>& arr,int k){
    vector<int> ans;
    deque<int> dq;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(!dq.empty() && dq.front()==i-k){
            dq.pop_front();
        }
        while(!dq.empty() && arr[i]>arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
        
        if(i>=k-1){
            ans.push_back(arr[dq.front()]);
        }

    }
    return ans;
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}