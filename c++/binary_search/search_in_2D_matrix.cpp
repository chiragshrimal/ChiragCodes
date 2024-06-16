#include<bits/stdc++.h>
using namespace std;

// brute force apporach 
// time complexity is O(n*m)
// space complexity is O(1)

bool search_brute(vector<vector<int>>& v,int target){
    int n=v.size();
    int m=v[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==target){
                return true;
            }
        }
    }
    return false;
}
bool binary_search_itrative(vector<int>& v,int n,int target){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+((high-low)>>1);
        if(target==v[mid]){
            return true;
        }
        if(target<v[mid]){
            high=mid-1;
        }else{
            low=mid+1;
        }

    }
    return false;
}
// better apporach 
// time complexity is O(n +log(m))
// space complexity is O(1)

bool search_better(vector<vector<int>>& v,int target){
    int n=v.size();
    int m=v[0].size();
    for(int i=0;i<n;i++){
        if(target>=v[i][0] && target<=v[i][m-1]){
            bool check=binary_search_itrative(v[i],m,target);
        if(check==true){
            return true;
        }
    }
    } 
    return false;
}

// optimal solution 
// time complexity is O(log(n*m))
// space complexity is o(1)

bool search_optimal(vector<vector<int>>& v,int target){
    int n=v.size();
    int m=v[0].size();
    int low=0;
    int high=m*n-1;
    while(low<=high){
        int mid=low+((high-low)>>1);
        int row=mid/m;
        int col=mid%m;
        if(v[row][col]==target){
            return true;
        }
        if(target<v[row][col]){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return false;
}
int main(){
 int n,m;
    cin>>n>>m;
    int target;
    cin>>target;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    int brute=search_brute(v,target);
    cout<<brute<<endl;

    int better=search_better(v,target);
    cout<<better<<endl;

    int optimal=search_optimal(v,target);
    cout<<optimal<<endl;
}