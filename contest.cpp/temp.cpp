#include<bits/stdc++.h>
using namespace std;
long long countCompleteDayPairs(vector<int>& v) {
        int n=v.size();
        for(int i=0;i<n;i++){
            v[i]=v[i]%24;
            // cout<<v[i]<<endl;
        }
        int hash[25]={0};
        for(int i=0;i<n;i++){
            hash[v[i]]++;
        }
        // for(int i=0;i<25;i++){
        //     cout<<hash[i]<<endl;
        // }
        long long int cnt=0;
        for(int i=0;i<n;i++){
            if(v[i]==0){
                cnt+=hash[0]-1;
            }else{
                 if(hash[24-v[i]]!=0){
                cnt+=1ll*hash[24-v[i]]-1;
            }
            }
        }
        return cnt/2;
        
    }
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int brute=countCompleteDayPairs(v);
    cout<<brute<<endl;
}   