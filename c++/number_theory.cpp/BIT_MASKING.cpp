#include<bits/stdc++.h>
using namespace std;

int count_setbit(int n){
    int count=0;
    for(int i=0;i<32;i++){
        if((n&(1<<i))!=0){
            count++;
        }
    }
    return count ;
}
int main(){
    /// jab bhi array ke bitch intersection lena hon or number of digits is less than 64 
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        int mark=0;
        int x;
        cin>>x;
        for(int j=0;j<x;j++){
            int m;
            cin>>m;
            mark=(mark|(1<<m));
           // cout<<mark<<endl;
        }
        //v.push_back(mark);
        v[i]=mark;
    }
    int ct=0;
    int max_count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int m=(v[i]&v[j]);
            ct=count_setbit(m);//O(1) 
            if(max_count<ct){
                max_count=ct;
            }
        }
    }
    cout<<max_count<<endl;
}