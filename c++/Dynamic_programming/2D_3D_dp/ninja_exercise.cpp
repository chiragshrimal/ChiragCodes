#include<bits/stdc++.h>
using namespace std;

// brute force apporach 
// time complexiity is o(2^n)
// space complexity is O(n)

int brute_apporach(int row,int col,vector<vector<int>>&arr){
    if(row==0){
        int maxi=0;
        for(int i=0;i<=2;i++){
            if(i!=col){
                maxi=max(maxi,arr[row][i]);
            }
        }
        return maxi;
    }
    int maxi=0;
    for(int i=0;i<=2;i++){
        if(i!=col){
            maxi=max(maxi,arr[row][i]+brute_apporach(row-1,i,arr));
        }
    }
    return maxi;
}

// optimal apporach 
// time complexity is o(n*4*3)
// space complexity is O(n)+O(n*4)

int top_down_optimal_apporach(int row,int col,vector<vector<int>>&arr,vector<vector<int>>&dp){
     if(row==0){
        int maxi=0;
        for(int i=0;i<=2;i++){
            if(i!=col){
                maxi=max(maxi,arr[row][i]);
            }
        }
        return maxi;
    }
    if(dp[row][col]!=-1){
        return dp[row][col];
    }
    int maxi=0;
    for(int i=0;i<=2;i++){
        if(i!=col){
            maxi=max(maxi,arr[row][i]+top_down_optimal_apporach(row-1,i,arr,dp));
        }
    }
    return dp[row][col]=maxi;
}

// bottom-up apporach 
// time complexity is O(n*4)
// space complexity is O(n)+O(n*4)

int bottom_apporach(vector<vector<int>>&arr){
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(4,0));
    // base case
    dp[0][0]=max(arr[0][1],arr[0][2]);
    dp[0][1]=max(arr[0][2],arr[0][0]);
    dp[0][2]=max(arr[0][1],arr[0][0]);
    dp[0][3]=max(arr[0][1],max(arr[0][0],arr[0][2]));
    
    for(int days=1;days<=n-1;days++){
        for(int last=0;last<=3;last++){
            dp[days][last]=0;
            for(int task=0;task<=2;task++){
                if(task!=last){
                    dp[days][last]=max(dp[days][last], arr[days][task]+dp[days-1][task]);
                }
            }
        }
    }
    return dp[n-1][3];
}

// do space optimization 
// time complexity  is o(n*4)
// space complexity is O(1)

int space_optimization(vector<vector<int>>&arr){
    int n=arr.size();
    vector<int> pre(4,0);
    // base case
    pre[0]=max(arr[0][1],arr[0][2]);
    pre[1]=max(arr[0][2],arr[0][0]);
    pre[2]=max(arr[0][1],arr[0][0]);
    pre[3]=max(arr[0][1],max(arr[0][0],arr[0][2]));
    
    for(int days=1;days<=n-1;days++){
        vector<int>temp(4,0);
        for(int last=0;last<=3;last++){
            temp[last]=0;
            for(int task=0;task<=2;task++){
                if(task!=last){
                    temp[last]=max(temp[last],arr[days][task]+pre[task]);
                }
            }
        }
        pre=temp;
    }
    return pre[3];
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(3,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }

    cout<<"using brute apporach "<<endl;
    int brute=brute_apporach(n-1,3,arr);
    cout<<brute<<endl;

    vector<vector<int>> dp(n,vector<int>(4,-1));
    cout<<"using top down apporach "<<endl;
    int optimal=top_down_optimal_apporach(n-1,3,arr,dp);
    cout<<optimal<<endl;
    
    cout<<"using bottom ap apporach "<<endl;
    int bottom=bottom_apporach(arr);
    cout<<bottom<<endl;

    cout<<"using space optimization "<<endl;
    int space = space_optimization(arr);
    cout<<space<<endl;

}