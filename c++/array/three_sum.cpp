#include<bits/stdc++.h>
using namespace std;
//q 
// find all triplet whose sum is zero (unique triplet)
// brute force apporach 
// time complexity is o(n^3)
// space complexity is O(1)
set<vector<int>> sum_brute(vector<int>& v ){
    set<vector<int>> s;
    int n=v.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(v[i]+v[j]+v[k]==0){
                    vector<int> temp={v[i],v[j],v[k]};
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
                }
            }
        }
    }
    return s;
}
// better apporac
int main(){
    cout<<"hello"<<endl;
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<"hello"<<endl;
    set<vector<int>> brute=sum_brute(v);
    for(auto it : brute){
        for(auto k : it){
            cout<<k<<" ";
        }
        cout<<endl;
    }
}