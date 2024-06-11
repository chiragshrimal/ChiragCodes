#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
void f(int index,vector<int>& temp,int k,vector<int>& v){
            if(k==0){
                ans.push_back(temp);
                return ;
            }
        for(int i=index;i<v.size();i++){
            if(i!=index && v[i]==v[i-1]){
                continue;
            }
            temp.push_back(v[i]);
            k=k-v[i];
            f(i+1,temp,k,v);
            k=k+v[i];
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& v, int k) {
        sort(v.begin(),v.end());
        vector<int> temp;
        // cout<<"hello"<<endl;
        f(0,temp,k,v);
        // cout<<"hello"<<endl;
        return ans;
}
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    // for(auto it : v){
    //     cout<<it<<endl;
    // }
    vector<vector<int>> s=combinationSum2(v,k);
    for(auto it : s){
        for(auto it2 :it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
}
