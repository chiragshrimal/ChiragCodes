#include<bits/stdc++.h>
using namespace std;
vector<int> occurrencesOfElement(vector<int>& v, vector<int>& q, int x) {
        int n=v.size();
        int k=q.size();
        vector<int> fre;
        for(int i=0;i<n;i++){
            if(v[i]==x){
                fre.push_back(i);
            }
        }
        int m=fre.size();
        vector<int> ans;
        for(int i=0;i<k;i++){
            if(q[i]>m){
                ans.push_back(-1);
            }else{
                ans.push_back(fre[q[i]]);
            }
        }
        return ans;
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
    int m;
    cin>>m;
    vector<int> q;
    for(int i=0;i<m;i++){
        int y;
        cin>>y;
        q.push_back(y);
    }
    int  x;
    cin>>x;
    vector<int> ans=occurrencesOfElement( v,q,x);
    for(auto it : ans){
        cout<<it<<endl;
    }
}  