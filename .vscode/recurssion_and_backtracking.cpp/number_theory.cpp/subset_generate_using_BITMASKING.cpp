#include<bits/stdc++.h>
using namespace std;

int main (){
    int n;
    cin>>n;
    int a[n];
    vector<vector<int>> subsets;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<pow(2,n);i++){
         vector<int> v;
        for(int j=0;j<n;j++){
            if((i&(1<<j))!=0){
                v.push_back(a[j]);
            }
        }
        subsets.push_back(v);
    }
    for(auto value :subsets){
        for(auto ele : value){
            cout<<ele<<" ";
        }
        cout<<endl;
    }

}