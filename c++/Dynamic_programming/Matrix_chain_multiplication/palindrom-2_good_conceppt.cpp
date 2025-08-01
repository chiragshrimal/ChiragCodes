#include <bits/stdc++.h>
using namespace std;

// brute force apporach
// time complexity is O(exponential)
// space complexity is O(n)
bool check_palindrom(string &str, int i, int j)
{
    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int brute_apporach(string &str, int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if (check_palindrom(str, i, j))
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp = INT_MAX;
        if (check_palindrom(str, i, k))
        {
            temp = 1 + brute_apporach(str, k + 1, j);
        }
        ans = min(ans, temp);
    }
    return ans;
}

// but in the above brute apporach
// j is not moving then why you pass this as a parameter

// better_apporach
// time complexity is o(exponential)
// space complexity is O(n^2 + n)
int better_apporach(string &str, int i)
{
    if (i == str.size() - 1)
    {
        return 0;
    }
    if (check_palindrom(str, i, str.size() - 1))
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int k = i; k <= str.size() - 1; k++)
    {
        int temp = INT_MAX;
        if (check_palindrom(str, i, k))
        {
            temp = 1 + better_apporach(str, k + 1);
        }
        ans = min(ans, temp);
    }
    return ans;
}

// memo top_down apporach
// time complexity is O(n^3)
// space complexity is O(n^2 +n)

int memo_top_down(string &str, int i, vector<int> &dp)
{
    if (i == str.size() - 1)
    {
        return 0;
    }
    if (check_palindrom(str, i, str.size() - 1))
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int ans = INT_MAX;
    for (int k = i; k <= str.size() - 1; k++)
    {
        int temp = INT_MAX;
        if (check_palindrom(str, i, k))
        {
            temp = 1 + memo_top_down(str, k + 1, dp);
        }
        ans = min(ans, temp);
    }
    return dp[i] = ans;
}

// but why we are compute palindrom again and agin
// most optimal apporach
// store all the palindrom string

// time compelxity is o(n^2)
// space complexity is O(n^2)
void store_palindrom(string &str, vector<vector<int>> &palin)
{
    int n = str.size();
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j <= n - 1; j++)
        {
            if (str[i] == str[j] && (j - i < 2 || palin[i + 1][j - 1]))
            {
                palin[i][j] = 1;
            }
        }
    }
    return;
}

// optimal memo top down apporach
// time complexity is O(n^2)
// space complexity is O(n^2 +n +n)
int optimal_memo_top_down(string &str, int i, vector<int> &dp, vector<vector<int>> &palin)
{
    if (i == str.size() - 1)
    {
        return 0;
    }
    if (palin[i][str.size() - 1] == 1)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int ans = INT_MAX;
    for (int k = i; k <= str.size() - 1; k++)
    {
        int temp = INT_MAX;
        if (palin[i][k] == 1)
        {
            temp = 1 + optimal_memo_top_down(str, k + 1, dp, palin);
        }
        ans = min(ans, temp);
    }
    return dp[i] = ans;
}

// most optimal bottom upp apporach
// time complexity is O()
// space compelxity is O()

int bottom_up_apporach(string &str, vector<vector<int>> &palin)
{
    int n = str.size();
    vector<int> dp(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        if (palin[i][str.size() - 1] == 1)
        {
            dp[i] = 0;
            continue;
        }
        int ans = INT_MAX;
        for (int k = i; k <= str.size() - 1; k++)
        {
            int temp = INT_MAX;
            if (palin[i][k] == 1)
            {
                temp = 1 + optimal_memo_top_down(str, k + 1, dp, palin);
            }
            ans = min(ans, temp);
        }
        dp[i] = ans;
    }
    return dp[0];
}

int main()
{
    string str;
    cin >> str;
    int n = str.size();

    cout << "brute apporach" << endl;
    int brute = brute_apporach(str, 0, n - 1);
    cout << brute << endl;

    cout << "using better apporach " << endl;
    int better = better_apporach(str, 0);
    cout << better << endl;

    cout << "using memo_top_down" << endl;
    vector<int> dp(n, -1);
    int memo = memo_top_down(str, 0, dp);
    cout << memo << endl;

    cout << "using optimal memo apporach " << endl;
    vector<vector<int>> palin(n, vector<int>(n, 0));
    store_palindrom(str, palin);
    vector<int> dp2(n, -1);
    int optimal = optimal_memo_top_down(str, 0, dp2, palin);
    cout << optimal << endl;

    cout<<"bottom up apporach "<<endl;
    int bottom=bottom_up_apporach(str,palin);
    cout<<bottom<<endl;
}