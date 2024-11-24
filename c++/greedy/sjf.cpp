#include<bits/stdc++.h>
using namespace std;

// optimal  apporach 
// time complexity is O(n*log(n))
// space complxity is O(1)

long long solve(vector<int>& bt) {
        int n=bt.size();
        long long int sum=0;
        sort(bt.begin(),bt.end());
        int k=n-1;
        for(int i=0;i<n-1;i++){
            sum=sum+k*1ll*bt[i];
            k--;
        }
        return sum/n;
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
    bool check=solve(v);
    cout<<check<<endl;
}