#include<bits/stdc++.h>
using namespace std;
//q<=10^6
//n<=10^7;
// find prime number for each query
const int N=1e5+9;
int main (){
    int n;
    cin>>n;
    vector<int>divisor[n];
    for(int i=2;i<n;++i){
        for(int j=i;j<n;j+=i){
            divisor[j].push_back(i);
        }
    }
    for(auto value : divisor){
        for(auto ele : value){
        cout<<ele<<" ";
        }
        cout<<endl;

    }
}