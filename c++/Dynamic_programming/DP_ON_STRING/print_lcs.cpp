#include<bits/stdc++.h>
using namespace std;

// optimal apporach 
// good concept;
void solve(int index1,int index2,string &s,string &t,string ans,set<string> &result,vector<vector<int>> &dp,unordered_map<string,bool>& memo){
        if(index1==0 || index2==0){
            reverse(ans.begin(),ans.end());
            result.insert(ans);
            return ;
        }
        string key=to_string(index1)+","+to_string(index2)+","+ans;
        if(memo[key]==true){
            return ;
        }
        memo[key]=true;
        
        if(s[index1-1]==t[index2-1]){
            ans.push_back(s[index1-1]);
            solve(index1-1,index2-1,s,t,ans,result,dp,memo);
            ans.pop_back();
        }else{
            if(dp[index1-1][index2]>dp[index1][index2-1]){
                solve(index1-1,index2,s,t,ans,result,dp,memo);
            }else{
                if(dp[index1-1][index2]==dp[index1][index2-1]){
                    solve(index1-1,index2,s,t,ans,result,dp,memo);
                    solve(index1,index2-1,s,t,ans,result,dp,memo);
                    
                }else{
                    solve(index1,index2-1,s,t,ans,result,dp,memo);
                }
            }
        }
        
    }
int Bottom_up(string &arr1,string &arr2,vector<vector<int>>& dp){
    int n1=arr1.size();
    int n2=arr2.size();
    for(int i=0;i<n1;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<n2;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(arr1[i-1]==arr2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n1][n2];
}
int main(){
    string s;
    string t;
    cin>>s;
    cin>>t;
    int n1=s.size();
    int n2=t.size();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
    int length=Bottom_up(s,t,dp);
    set<string> result;
    unordered_map<string,bool> memo;
    solve(n1,n2,s,t,"",result,dp,memo);
    vector<string>v(result.begin(),result.end());
    for(auto it : v){
        cout<<it<<endl;
    }
}