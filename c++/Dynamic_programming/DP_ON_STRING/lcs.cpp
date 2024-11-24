#include<bits/stdc++.h>
using namespace std;

// brute force apporach 
// time complexity is O(2^n * 2^m)
// space complextiy is O(n+m)
int brute_apporach(int index1,int index2,string &arr1,string &arr2){
        if(index1<0 || index2<0){
            return 0;
        }
        if(index1==0 || index2==0){
            if(arr1[index1]==arr2[index2]){
                return 1;
            }
            if(index1==0 && index2==0){
                if(arr1[index1]==arr2[index2]){
                    return 1;
                }
                return 0;
            }

        }
        if(arr1[index1]==arr2[index2]){

            return 1+brute_apporach(index1-1,index2-1,arr1,arr2);
        }
        int b=brute_apporach(index1-1,index2,arr1,arr2);
        int c=brute_apporach(index1,index2-1,arr1,arr2);
        return max(b,c);
}

// top-Down apporach 
// time compelxity is O(n*m)
// space complexity is O(n*m)+O(n+m)
int top_Down(int index1,int index2,string &arr1,string &arr2,vector<vector<int>>&dp){
    if(index1<0 || index2<0){
            return 0;
        }
        if(index1==0 || index2==0){
            if(arr1[index1]==arr2[index2]){
                return 1;
            }
            if(index1==0 && index2==0){
                if(arr1[index1]==arr2[index2]){
                    return 1;
                }
                return 0;
            }

        }
        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }

        if(arr1[index1]==arr2[index2]){

            return dp[index1][index2]=1+top_Down(index1-1,index2-1,arr1,arr2,dp);
        }
        int b=top_Down(index1-1,index2,arr1,arr2,dp);
        int c=top_Down(index1,index2-1,arr1,arr2,dp);
        return dp[index1][index2]=max(b,c);
}

// bottom_up apporach 
// time complexity is O(n*m)
// space compelxity is O(n*m)

int Bottom_up(string &arr1,string &arr2){
    int n1=arr1.size();
    int n2=arr2.size();
    vector<vector<int>> dp(n1,vector<int>(n2,0));
    if(arr1[0]==arr2[0]){
        dp[0][0]=1;
    }
    for(int i=1;i<n1;i++){
        if(arr1[i]==arr2[0]){
            dp[i][0]=1;
        }else{
            dp[i][0]=dp[i-1][0];
        }
    }
    for(int i=1;i<n2;i++){
        if(arr1[0]==arr2[i]){
            dp[0][i]=1;
        }else{
            dp[0][i]=dp[0][i-1];
        }
    }
    for(int i=1;i<n1;i++){
        for(int j=1;j<n2;j++){
            if(arr1[i]==arr2[j]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            cout<<dp[i][j];
        }
        cout<<endl;
    }
    return dp[n1-1][n2-1];

    
}
// we can again optimize space complexity 
// space complexity is O(max(n,m))


int main(){
    string str1;
    cin>>str1;
    string str2;
    cin>>str2;
    int n1=str1.size();
    int n2=str2.size();
    int brute=brute_apporach(n1-1,n2-1,str1,str2);
    cout<<brute<<endl;
    vector<vector<int>> dp(n1,vector<int>(n2,-1));
    int top=top_Down(n1-1,n2-1,str1,str2,dp);

    int bottom=Bottom_up(str1,str2);
    cout<<bottom<<endl; 
}