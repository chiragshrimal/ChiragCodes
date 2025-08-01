#include <bits/stdc++.h>
using namespace std;

// brute force apporach
// time complexity is O(exponential)
// space complexity is O(m)

long long int brute_apporach(vector<int> &arr, int i, int j)
{
    if (i > j)
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int k = i; k <= j; k++)
    {
        int temp = arr[j + 1] - arr[i - 1] + brute_apporach(arr, i, k - 1) + brute_apporach(arr, k + 1, j);
        ans = min(ans, temp);
    }
    return ans;
}

// memorize top down apporach
// time complexity is O(m^3)
// space complexity is O(m^2)+o(m)

long long int memorize_top_down_apporach(vector<int> &arr, int i, int j, vector<vector<long long int>> &dp)
{
    if (i > j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = INT_MAX;
    for (int k = i; k <= j; k++)
    {
        int temp = arr[j + 1] - arr[i - 1] + memorize_top_down_apporach(arr, i, k - 1, dp) + memorize_top_down_apporach(arr, k + 1, j, dp);
        ans = min(ans, temp);
    }
    return dp[i][j] = ans;
}

// bottom ap apporach
// time complexity is O(m^3)
// space complexity is o(m*m)

long long int bottom_up_apporach(vector<int> &arr)
{
    int m = arr.size();
    int cuts_size=m-2;
    vector<vector<long long int>> dp(cuts_size+2, vector<long long int>(cuts_size+2, 0));
    for (int i = cuts_size; i >= 1; i--)
    {
        for (int j = i; j <= cuts_size; j++)
        {
            int ans = INT_MAX;
            for (int k = i; k <= j; k++)
            {
                int temp = arr[j + 1] - arr[i - 1] + dp[i][k-1] + dp[k+1][j];
                ans = min(ans, temp);
            }
            dp[i][j] = ans;
        }
    }
    return dp[1][cuts_size];
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> cuts(m, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> cuts[i];
    }
    vector<int> arr(m + 2, 0);
    arr[0] = 0;
    arr[m + 1] = n;
    for (int i = 1; i <= m; i++)
    {
        arr[i] = cuts[i - 1];
    }
    // you have to sorted first 
    sort(arr.begin(),arr.end());
    cout << "using brute apporach" << endl;
    long long int brute = brute_apporach(arr, 1, m);
    cout << brute << endl;

    cout << "using memorize top_down apporach" << endl;
    vector<vector<long long int>> dp(m + 1, vector<long long int>(m + 1, -1));
    long long int memo =  memorize_top_down_apporach(arr, 1, m ,dp);
    cout << memo << endl;

    cout << "using bottom ap apporach " << endl;
    long long int b = bottom_up_apporach(arr);
    cout << b << endl;
}