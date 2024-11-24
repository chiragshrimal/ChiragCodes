#include<bits/stdc++.h>
using namespace std;

// optimal apporach 
// time complextiys is O(n^2)
// space complexity is O(n^2)

int solve(string &str1,string &str2){
     int n1=str1.size();
        int n2=str2.size();
        vector<vector<int>> ans(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(str1[i-1]==str2[j-1]){
                    ans[i][j]=1+ans[i-1][j-1];
                }
            }
        }
        int maxi=0;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(maxi<ans[i][j]){
                    maxi=ans[i][j];
                }
            }
        }
        return maxi;
}

int main(){
    string str1;
    string str2;
    cin>>str1;
    cin>>str2;
    int ans=solve(str1,str2);
    cout<<ans<<endl;
}