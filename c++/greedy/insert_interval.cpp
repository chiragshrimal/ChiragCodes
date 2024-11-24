#include<bits/stdc++.h>
using namespace std;

// optimal solution 
// time complexity is O(n)
// space complexity is O(1);

vector<vector<int>> insert_merge(vector<vector<int>>& interval,vector<vector<int>>& newinterval){
    int n=interval.size();
    vector<vector<int>> ans;
    int i=0;
    // left part
    while(i<n  && interval[i][1]<newinterval[0][0]){
        ans.push_back(interval[i]);
        i++;
    }
    // middle part
    while(i<n && interval[i][0]<=newinterval[0][1]){
        newinterval[0][0]=min(newinterval[0][0],interval[i][0]);
        newinterval[0][1]=max(newinterval[0][1],interval[i][1]);
        i++;
    }
    ans.push_back(newinterval[0]);
    while(i<n){
        ans.push_back(interval[i]);
        i++;
    }
    return ans;


}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> v;
    vector<vector<int>> insert;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        int y;
        cin>>y;
        v.push_back({x,y});
    }
    int x;
    cin>>x;
    int y;
    cin>>y;
    insert.push_back({x,y});
    vector<vector<int>> ans=insert_merge(v,insert);
    for(auto it : ans){
        for(auto it2 : it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
}