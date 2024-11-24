#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subset;

void generate(vector<int> &v,int i,vector<int>nums){
    if(i==nums.size()){
        subset.push_back(v);
        return ;
    }
    generate(v,i+1,nums);

    v.push_back(nums[i]);
    generate(v,i+1,nums);
    v.pop_back();
}
int main (){
    int n;
    cin>>n;
    vector<int> empty;
    vector<int>nums;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    generate(empty,0,nums);
    for(auto value :subset){
        for(auto ele : value){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}