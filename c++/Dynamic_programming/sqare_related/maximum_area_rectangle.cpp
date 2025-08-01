#include<bits/stdc++.h>
using namespace std;

// this below histogram program already done in the stack topic 
int maximum_area_histogram(vector<int>& arr){

    vector<int> left=nearest_smaller_left(arr);
    for(auto it : left){
        cout<<it;
    }
    cout<<endl;
    vector<int> right= nearest_smaller_right(arr);
    for(auto it : right){
        cout<<it;
    }

    int n=arr.size();
    int maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,abs(arr[i]*(abs(left[i]-right[i])-1)));
    }
    return maxi;
}

int solve(vector<vector<int>>&matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    vector<int> ans(m,0);
    int maxi=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                ans[0][j]=0;
            }else{
                ans[i][j]+=1;
            }
            maxi=max(maxi,maximum_area_histogram(ans));
        }
    }
    return maxi;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int ans=solve(arr);
    cout<<ans<<end;
}