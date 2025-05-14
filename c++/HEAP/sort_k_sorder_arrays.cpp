#include<bits/stdc++.h>
using namespace std;

// brute force apporach 
// time complexity is O(k^2) + O(k^2*log(k^2))
// space complexity is O(k^2)
// using merge sort 



// optimal apporach 
// time complexity is o(k^2*log(k))
// space complexity is o(k)

vector<int> optimal_apporach(vector<vector<int>>&arr, int k){
    int z=k*k-1;
    vector<int> ans(k*k,0);
    priority_queue<pair<int,pair<int,int>>> H;
    for(int i=0;i<k;i++){
        H.push(pair(arr[i][k-1],pair(i,k-1)));
    }

    while(z>=0){
        int row=H.top().second.first;
        int col=H.top().second.second;
        ans[z]=arr[row][col];
        z--;
        col--;
        H.pop();
        if(col>=0){
            H.push(pair(arr[row][col],pair(row,col)));
        }
    }
    return ans;
}

int main(){
    int k;
    cin>>k;
    vector<vector<int>> arr(k,vector<int>(k,0));
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            cin>>arr[i][j];
        }
    }
    vector<int> ans=optimal_apporach(arr,k);
    for(int i=0;i<k*k;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}