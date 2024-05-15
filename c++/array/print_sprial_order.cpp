#include<bits/stdc++.h>
using namespace std;
// good question 
vector<int> sprial_print(vector<vector<int>> &v){
    int n=v.size();
    int m=v[0].size();
    int i=0;
    int j=0;
    vector<int> ans;
    while(i<n && j<m){
        for(int k=j;k<m;k++){
            ans.push_back(v[i][k]);
        }
        i++;
        for(int k=i;k<n;k++){
            ans.push_back(v[k][m-1]);
        }
        m--;
        if(i<n){
        for(int k=m-1;k>=j;k--){
            ans.push_back(v[n-1][k]);
        } 
        }
        n--;
        if(j<m){
        for(int k=n-1;k>=i;k--){
            ans.push_back(v[k][j]); 
        }
        }
        j++;
    }
    return ans;

}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    cout<<"hello"<<endl;
    vector<int> ans=sprial_print(v);
    for(auto it : ans){
        cout<<it<<endl;
    }
}