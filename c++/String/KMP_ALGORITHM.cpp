#include<bits/stdc++.h>
using namespace std;


// time complexity of LPS is O(m)
// space complexity is O(m)
vector<int> computeLps(string &pattern){
    int m=pattern.size();
    vector<int> lps(m,0);
    int len=0;
    int i=1;
    while(i<m){
        if(pattern[len]==pattern[i]){
            len++;
            lps[i]=len;
            i++;
        }else{
            if(len!=0){
                len=lps[i-1];
            }else{
                i++;
            }
        }
    }
    return lps;
}

// time complexity is O(n+m)
// space complexity is o(m)
bool KMP(string &s, string &pattern){
    int n=s.size();
    int m=pattern.size();
    vector<int> lps=computeLps(pattern);
    int i=0;
    int j=0;
    while(i<n){
        if(s[i]==pattern[j]){
            i++;
            j++;
        }
        if(j==m){
            // you can also return the starting aqnd ending point of the matching
            return true;
        }else{
            if(i<n && s[i]!=pattern[j]){
                if(j==0){
                    // ab koi chara nhi hai toh i ko aage bdana hi pdega 
                    i++;
                }else{
                    j=lps[j-1];
                }
            }
        }
    }
    return false;
}

int main(){
    string s, pattern;
    cin>>s;
    cin>>pattern;
}