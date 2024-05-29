#include<bits/stdc++.h>
using namespace std;

// brute force apporach 
// time complexity is O(n^2)
//space complexity is O(1)
int find_max(int*hash){
    int max=INT_MIN;
    for(int i=0;i<26;i++){
        if(max<hash[i]){
            max=hash[i];
        }
    }
    return max;
}

int longest_reapeting_brute(string str,int k){
    int n=str.size();
    int maxlength=0;
    for(int i=0;i<n;i++){
        int hash[26]={0};
        int max_fre=0;
        for(int j=i;j<n;j++){
            hash[str[j]-'A']++;
            max_fre=max(max_fre,hash[str[j]-'A']);
            if(j-i+1-max_fre <=k){
                maxlength=max(maxlength,j-i+1);
            }else{
                break;
            }
        }
    }
    return maxlength;
}
// OPTIMAL APPORACH 
// time complexity is O(2*n*26);
// space complexity is O(1)
   int longest_reapeting_optimal(string str, int k) {
    int n=str.size();
    int maxlength=0;
    int hash[26]={0};
    int count=0;
    int i=0;
    int j=0;
    int max_fre=0;
    while(j<n){
        hash[str[j]-'A']++;
        max_fre=max(max_fre,hash[str[j]-'A']);
        if(j-i+1-max_fre<=k){
            maxlength=max(maxlength,j-i+1);
        }else{
            while(j-i+1-max_fre>k){
                hash[str[i]-'A']--;
                i++;
                // max_fre=find_max(hash);// O(26)
            }
        }
        j++;   
    }
    return maxlength;
    }


// optmal apporach2 when we get maxlength then why we have to decrease length
// time complexity is O(n*26)
// space complexity is O(26)

int longest_reapeting_optimal2(string str, int k) {
    int n=str.size();
    int maxlength=0;
    int hash[26]={0};
    int count=0;
    int i=0;
    int j=0;
    int max_fre=0;
    while(j<n){
        hash[str[j]-'A']++;
        max_fre=max(max_fre,hash[str[j]-'A']);
        if(j-i+1-max_fre<=k){
            maxlength=max(maxlength,j-i+1);
        }else{
            if(j-i+1-max_fre>k){
                hash[str[i]-'A']--;
                i++;
                // max_fre=find_max(hash);
                // there no point to decrease the max_fre
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
    int brute=longest_reapeting_brute(s,k);
    cout<<brute<<endl;
    int optimal=longest_reapeting_optimal(s,k);
    cout<<optimal<<endl;
    int optimal2=longest_reapeting_optimal2(s,k);
    cout<<optimal2<<endl;

}