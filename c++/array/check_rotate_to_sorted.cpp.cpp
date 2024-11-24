#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> &v){
    int n=v.size();
    int index=-1;
    for(int i=0;i<n-1;i++){
        if(v[i]>v[i+1]){
            index=i;
        }
    }
    if(index==-1){
        return true;
    }
    for(int k=index;k<n-1;k++){
        if(v[k]>v[k+1]){
            return false;
        }
    }
    if(v[0]<v[n-1]){
        return false;
    }
    for(int k=0;k<=index-1;k++){
        if(v[k]>v[k+1]){
            return false;
        }
    }
    return true;
}
int main(){
    int n; 
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

}