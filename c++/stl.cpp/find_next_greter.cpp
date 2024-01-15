#include<bits/stdc++.h>
using namespace std;
int main (){
    // ydi tum map ka use nhi krna chah rhe toh stack m indexes bhej do 
    int n;
    cin>>n;
    stack<int> s;
    unordered_map<int ,int> m;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int brr[n];
    for(int i=0;i<n;i++){
        if(s.empty()){
            s.push(arr[i]);
        }else{
            while(!s.empty() && arr[i]>s.top()){
                m[s.top()]=arr[i];
                s.pop();
            }
            s.push(arr[i]);
        }
    }
    while(!s.empty()){
        m[s.top()]=-1;
        s.pop();
    }
    for(int i=0;i<n;i++){
        brr[i]=m[arr[i]];
    }
    for(int i=0;i<n;i++){
        cout<<brr[i]<<" ";
    }

}