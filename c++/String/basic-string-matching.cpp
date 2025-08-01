#include<bits/stdc++.h>
using namespace std; 

bool stringMatching(string &s, string &pattern){
    int n=s.size();
    int m=pattern.size();
    for(int i=0;i<n;i++){
        if(s[i]!=pattern[0])  continue;
        int k=0;
        for(int j=i;j<min(n,m);j++){
            if(s[j]==pattern[k]){
                k++;
            }else{
                break;
            }
            if(k==n) return true;
        }
    }
    return false;
}


int main(){
    string s, pattern;
    cin>>s;
    cin>>pattern;
    bool ans= stringMatching(s,pattern);
    if(ans){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return ;
}