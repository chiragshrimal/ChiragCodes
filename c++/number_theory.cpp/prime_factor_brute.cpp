#include<bits/stdc++.h>
using namespace std;

// time complexity is O(sqrt(n))
// space complexity is O(n);
// find first prime factor
// and calculate all other prime factor
vector<int> prime_brute(int n){
    vector<int> v;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            v.push_back(i);
            n/=i;
        }
    }
    return v;
}
int main(){
    int n;
    cin>>n;
    vector<int> ans=prime_brute(n);
    for(auto it : ans){
        cout<<it<<endl;
    }
}