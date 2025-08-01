#include <bits/stdc++.h>
using namespace std;

// brute apporach
// time complexity  is o()
// space complexity is O()

int brute_apporach(vector<int> &arr, int i, int j)
{
    if (j < i)
    {
        return 0;
    }
    int ans = INT_MIN;
    for (int k = i; k <= j; k++)
    {
        int temp = arr[i - 1] * arr[k] * arr[j + 1] + brute_apporach(arr, i, k - 1) + brute_apporach(arr, k + 1, j);
        ans = max(ans, temp);
    }
    return ans;
}

int memorize_top_Down(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
{
    if (j < i)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = INT_MIN;
    for (int k = i; k <= j; k++)
    {
        int temp = arr[i - 1] * arr[k] * arr[j + 1] + memorize_top_Down(arr, i, k - 1, dp) + memorize_top_Down(arr, k + 1, j, dp);
        ans = max(ans, temp);
    }
    return dp[i][j] = ans;
}

// bottom up apporach
// time compelxity is O()
// space compplexity is o()

int bottom_up_apporach(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 2; i >= 1; i--)
    {
        for (int j = i; j <= n - 2; j++)
        {
            int ans = INT_MIN;
            for (int k = i; k <= j; k++)
            {
                int temp = arr[i - 1] * arr[k] * arr[j + 1] + dp[i][k-1] + dp[k+1][j];
                ans = max(ans, temp);
            }
            dp[i][j] = ans;
        }
    }
    return dp[1][n-2];
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // we have to insert 1 and 1 start and first
    arr.insert(arr.begin() + 0, 1);
    arr.push_back(1);
    n = arr.size();
    cout << "using brute apporach " << endl;
    int brute = brute_apporach(arr, 1, n - 2);
    cout << brute << endl;

    cout << "using memo apporaach " << endl;
    vector<vector<int>> dp(n - 1, vector<int>(n - 1, -1));
    int memo = memorize_top_Down(arr, 1, n - 2, dp);
    cout << memo << endl;

    cout<<"bottom_up_apporach"<<endl;
    int bottom=bottom_up_apporach(arr);
    cout<<bottom<<endl;
}