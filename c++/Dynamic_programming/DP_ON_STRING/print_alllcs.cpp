#include <bits/stdc++.h>
using namespace std;
void solve(int index1, int index2, string &s, string &t, string ans, set<string> &result, vector<vector<int>> &dp)
{

    if (index1 == 0 || index2 == 0)
    {
        reverse(ans.begin(), ans.end());
        result.insert(ans);
        return;
    }

    if (s[index1 - 1] == t[index2 - 1])
    {
        ans.push_back(s[index1 - 1]);
        solve(index1 - 1, index2 - 1, s, t, ans, result, dp);
    }
    else
    {
        if (dp[index1 - 1][index2] > dp[index1][index2 - 1])
        {
            solve(index1 - 1, index2, s, t, ans, result, dp);
        }
        else
        {
            if (dp[index1 - 1][index2] == dp[index1][index2 - 1])
            {
                solve(index1 - 1, index2, s, t, ans, result, dp);
                solve(index1, index2 - 1, s, t, ans, result, dp);
            }
            else
            {
                solve(index1, index2 - 1, s, t, ans, result, dp);
            }
        }
    }
}
int Bottom_up(string &arr1, string &arr2,vector<vector<int>>&dp)
{
    int n1 = arr1.size();
    int n2 = arr2.size();
    for (int i = 0; i <= n1; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= n2; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (arr1[i - 1] == arr2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n1][n2];
}
int main()
{
    string s,t;
    cin>>s;
    cin>>t;
    int n1 = s.size();
    int n2 = t.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    int length = Bottom_up(s, t, dp);
    set<string> result;
    solve(n1, n2, s, t, "", result, dp);

    for(auto it : result){
        cout<<it<<endl;
    }
}