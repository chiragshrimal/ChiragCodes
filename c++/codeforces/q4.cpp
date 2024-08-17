#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    cout<<t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        string str;
        cin>>str;
        vector<int> presum(n+1,0);
        presum[0]=0;
        for(int i=0;i<n;i++){
            presum[i+1]=presum[i]+v[i];
        }

        long maxi=0;
        int i=0;
        int j=n-1;
        while(i<j){
            while(str[i]!='L'){
                i++;
            }
            while(str[j]!='R'){
                j--;
            }
            if(i<j){
                maxi=maxi+presum[j+1]-presum[i];
            }
        }
        cout<<maxi<<endl;
    }
}