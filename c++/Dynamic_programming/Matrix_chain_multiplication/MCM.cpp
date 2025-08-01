#include <bits/stdc++.h>
using namespace std;

// brute force apporach
// time complexity is O(exponential)
// space complexity is O(N)

int brute_apporach(vector<int> &arr, int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp = brute_apporach(arr, i, k) + brute_apporach(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        ans = min(ans, temp);
    }
    return ans;
}

// memorize_top_down apporach
// time complexity is O(n^3)
// space complexity is O(n^2) + O(n)

int memorize_top_down(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp = memorize_top_down(arr, i, k, dp) + memorize_top_down(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];
        ans = min(ans, temp);
    }
    return dp[i][j] = ans;
}

// bottom up apporach
// time complexity is O(n^3)
// space complexity is o(n)

int bottom_up_apporach(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 1; i--)
    {
        // please focus that j is always greater than i 
        for (int j =i+1; j<=n-1 ; j++)
        {
            int ans = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int temp = dp[i][k] + dp[k+1][j]+ arr[i - 1] * arr[k] * arr[j];
                ans = min(ans, temp);
            }
            dp[i][j]=ans;
        }
    }
    return dp[1][n-1];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"usong brute apporach "<<endl;
    int brute=brute_apporach(arr,1,n-1);
    cout<<brute<<endl;

    cout<<"using memorize top down apporach "<<endl;
    vector<vector<int>> dp(n,vector<int>(n,-1));
    int memo=memorize_top_down(arr,1,n-1,dp);
    cout<<memo<<endl;

    cout<<"using bottom up apporach "<<endl;
    int bottom=bottom_up_apporach(arr);
    cout<<bottom<<endl;
}