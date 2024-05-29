#include<bits/stdc++.h>
using namespace std;

//brute force apporach 
// time complexity is O(n^2)
// space complexity is O(k);
int longest_substring_brute(string str,int k){
    int n=str.size();
    int maxlength=0;
    for(int i=0;i<n;i++){
        set<char> s;
        for(int j=i;j<n;j++){
            s.insert(str[j]);
            if(s.size()<=k){
                maxlength=max(maxlength,j-i+1);
            }else{
                break;
            }
        }
    }
    return maxlength;
}
// optimal apporach 
// time complexity is O(2*n)
// space complexity is O(k)

int longest_substring_optimal(string str,int k){
    int n=str.size();
    unordered_map<char,int> m;
    int i=0;
    int j=0;
    int maxlength=0;
    while(j<n){
        m[str[j]]++;
        if(m.size()<=k){
            maxlength=max(maxlength,j-i+1);
        }else{
            while(m.size()>k){
                m[str[i]]--;
                if(m[str[i]]==0){
                    m.erase(str[i]);
                }
                i++;
            }
        }
        j++;
    }
    return maxlength;
}
// optimal apporach 2
// time complexity is O(n)
// space complexity is O(k)

int longest_substring_optimal2(string str,int k){
    int n=str.size();
    unordered_map<char,int> m;
    int i=0;
    int j=0;
    int maxlength=0;
    while(j<n){
        m[str[j]]++;
        if(m.size()<=k){
            maxlength=max(maxlength,j-i+1);
        }else{
            if(m.size()>k){
                m[str[i]]--;
                if(m[str[i]]==0){
                    m.erase(str[i]);
                }
                i++;
            }
        }
        j++;
    }
    return maxlength;
}


int main(){
    int k;
    cin>>k;
    string s;
    cin>>s;
    int brute=longest_substring_brute(s,k);
    cout<<brute<<endl;

    int optimal=longest_substring_optimal(s,k);
    cout<<optimal<<endl;

    int optimal2=longest_substring_optimal2(s,k);
    cout<<optimal2<<endl;
}