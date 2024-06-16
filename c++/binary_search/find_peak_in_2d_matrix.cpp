#include<bits/stdc++.h>
using namespace std;

pair<int,int> max_element(vector<vector<int>>& v,int col,int n){
    int max=INT_MIN;
    int row=-1;
    for(int i=0;i<n;i++){
        if(max<v[i][col]){
            max=v[i][col];
            row=i;
        }
    }
    return pair(max,row);
}



// brute force apporach using traverse in matrix
// time complexity is O(n*m)
// space complexity is O(1)


//optimal apporach 
// time complexity is O(n*log(m))
// space complexity is O(1)

vector<int> peak_in_2d(vector<vector<int>> & v){
    int n=v.size();
    int m=v[0].size();
    int low=0;
    int high=m-1;
    while(low<=high){
        int mid=low+((high-low)>>1);// colunm hai 
        pair<int,int> temp=max_element(v, mid,n);
        int left=mid-1>=0 ? v[temp.second][mid-1]:-1;
        int right=mid+1<m ? v[temp.second][mid+1]:-1;
    if(temp.first>left && temp.first>right){
            return {temp.second,mid};
        }else{
            if(left>temp.first){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
    }
    return {-1,-1};
}

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>> v;
    for(int j=0;j<n;j++){
        vector<int> temp;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        temp.push_back(x);
    }
    v.push_back(temp);
    }
    vector<int> ans=peak_in_2d(v);
    for(auto it : ans){
        cout<<it<<endl;
    }
    
}       