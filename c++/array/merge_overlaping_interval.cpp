#include<bits/stdc++.h>
using namespace std;

// optimal apporach 
/// time complexity is O(nlog(n)+n)
// space complexity is O(n)

vector<vector<int>> merge_overlapping(vector<vector<int>>& v){
    vector<vector<int>> ans;
    sort(v.begin(),v.end());
    int n=v.size();
    for(int i=0;i<n;i++){
        int start=v[i][0];
        int end=v[i][1];
        if(ans.empty()||ans.back()[1]<start){
            ans.push_back(v[i]);
        }else{
            ans.back()[1]=max(ans.back()[1],end);
        }

    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<2;j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    vector<vector<int>> ans=merge_overlapping(v);
    for(auto it : ans){
        cout<<"[";
        for(auto it2 : it){
            cout<<it2<<" ";
        }
        cout<<"]"<<endl;
    }

}