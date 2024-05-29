#include<bits/stdc++.h>
using namespace std;
// q. without reapeting character

// brute force apporach  without hashing 
// time complexity is O(n^3)
// space complexity is O(1);
int longest_substring_brute(string s){
    int n=s.length();
    int max=0;
    int i;
    for(int k=0;k<n;k++){
        int sum=0;
    for(i=k;i<n;i++){
        int flag=0;
        int temp;
        for(int j=i-1;j>=k;j--){
            if(s[i]==s[j]){
                temp=i;
                flag=1;
                break;
            }
        }
        if(flag!=1){
            sum=sum+1;
            if(max<sum){
                max=sum;
            }
        }else{
            break;
        }
    }
    }
    return max;

}
// better apporach  find all the without reapeating character string 
// time complexity is O(n^2)
//space complexity is O(256)

int longest_substring_better(string s){
    int n=s.length();
    int max=0;
    for(int i=0;i<n;i++){
        int  hash[256]={0};
        for(int j=i;j<n;j++){
            if(hash[s[j]]==1){
                break;
            }else{
                if(max<j-i+1){
                    max=j-i+1;
                }
                hash[s[j]]=1;
            }
        }
    }
    return max;
}
// optimal apporach 
// time complexity is O(n);
// space complexity is O(1)

int longest_substring_optimal(string s){
    int n=s.length();
    int i=0;
    int j=0;
    int maxlength=0;
    unordered_map<int,int> m;
    while(j<n){
        auto it =m.find(s[j]);
        if(it==m.end()){
            maxlength=max(maxlength,j-i+1);
        }else{
            if(it->second>=i){
                i=it->second+1;
            }else{
                maxlength=max(maxlength,j-i+1);
            }
        }
        m[s[j]]=j;
        j++;
    }
    return maxlength;
}

int main(){
    string s;
    cin>>s;
    int brute=longest_substring_brute(s);
    cout<<brute<<endl;

    int better=longest_substring_better(s);
    cout<<better<<endl;
    int optimal=longest_substring_optimal(s);
    cout<<optimal<<endl;
}