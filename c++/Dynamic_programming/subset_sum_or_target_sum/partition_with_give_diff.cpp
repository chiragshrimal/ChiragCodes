#include<bits/stdc++.h>
using namespace std;
int countPartitions(int n, int d, vector<int>& arr) {
        int m=1e9+7;
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+arr[i];
        }
        vector<vector<int>> dp(n,vector<int>(sum+1,0));
        vector<int>hash(n,0);
        int pre=0;
        int cur=0;
        if(arr[0]==0){
            pre=1;
            hash[0]=pre;
        }
        for(int i=1;i<n;i++){
            if(arr[i]==0){
                cur=pre+1;
                hash[i]=cur;
                pre=cur;
            }else{
                hash[i]=hash[i-1];
            }
        }
        for(int i=0;i<n;i++){
            dp[i][0]=1<<hash[i];
        }
            if(arr[0]!=0)
            dp[0][arr[0]]=1;
            
        for(int i=1;i<n;i++){
            for(int target=1;target<=sum;target++){
                
                long int nottake=dp[i-1][target]%m;
                long int take=0;
                if(target>=arr[i]){
                    take=dp[i-1][target-arr[i]]%m;
                }
                dp[i][target]=(take+nottake)%m;
            }
        }
        for(int i=0;i<=sum;i++){
            cout<<dp[n-1][i]<<" ";
        }
        cout<<endl;
        long int cnt=0;
        for(int i=0;i<=sum;i++){
            int s1=i;
            int s2=sum-i;
            if(s1-s2==d){
                cnt=cnt+dp[n-1][s1];
            }
        }
        return cnt;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int d;
    cin>>d;
    int diff=countPartitions(n,d,arr);
    cout<<diff<<endl;
}        


        