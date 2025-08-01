#include <bits/stdc++.h>
using namespace std;

// brurte force apporach
// time complexity is o(exponential)
// space ecomplexity is O(n^2 + n )

long long int brute_apporach(string &str, int i, int j, int is_True)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (is_True == 1)
        {
            return str[i] == 'T';
        }
        return str[i] == 'F';
    }
    long long int ways = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {
        long long int TL = brute_apporach(str, i, k - 1, 1);
        long long int TR = brute_apporach(str, k + 1, j, 1);
        long long int FL = brute_apporach(str, i, k - 1, 0);
        long long int FR = brute_apporach(str, k + 1, j, 0);
        if (str[k] == '&')
        {
            if (is_True == 1)
            {
                ways = ways + TL * TR;
            }
            else
            {
                ways = ways + TL * FR + FL * FR + FL * TR;
            }
        }
        if (str[k] == '|')
        {
            if (is_True == 1)
            {
                ways = ways + TL * TR + TL * FR + FL * TR;
            }
            else
            {
                ways = ways + FL * FR;
            }
        }
        if (str[k] == '^')
        {
            if (is_True == 1)
            {
                ways = ways + TL * FR + FL * TR;
            }
            else
            {
                ways = ways + TL * TR + FL * FR;
            }
        }
    }
    return ways;
}

// memorize top down apporach
// time complexity is o(n^3)
// space complexity is o(n^2 + n)

int memorize_top_down(string &str, int i, int j, int is_True, vector<vector<vector<int>>> &dp)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (is_True == 1)
        {
            return str[i] == 'T';
        }
        return str[i] == 'F';
    }
    if (dp[i][j][is_True] != -1)
    {
        return dp[i][j][is_True];
    }
    long long int ways = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {
        long long int TL = memorize_top_down(str, i, k - 1, 1, dp);
        long long int TR = memorize_top_down(str, k + 1, j, 1, dp);
        long long int FL = memorize_top_down(str, i, k - 1, 0, dp);
        long long int FR = memorize_top_down(str, k + 1, j, 0, dp);
        if (str[k] == '&')
        {
            if (is_True == 1)
            {
                ways = ways + TL * TR;
            }
            else
            {
                ways = ways + TL * FR + FL * FR + FL * TR;
            }
        }
        if (str[k] == '|')
        {
            if (is_True == 1)
            {
                ways = ways + TL * TR + TL * FR + FL * TR;
            }
            else
            {
                ways = ways + FL * FR;
            }
        }
        if (str[k] == '^')
        {
            if (is_True == 1)
            {
                ways = ways + TL * FR + FL * TR;
            }
            else
            {
                ways = ways + TL * TR + FL * FR;
            }
        }
    }
    return dp[i][j][is_True] = ways;
}

// bottom up apporach
// time complexity is O(n^3*2)
// space compelxity is O(n^2*2)

int bottom_up_apporach(string str)
{
    int n = str.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j <= n - 1; j++)
        {
            for (int is_True = 0; is_True <= 1; is_True++)
            {
                if(i==j){
                    if(str[i]=='T'){
                        if(is_True==1){
                            dp[i][j][is_True]=1;
                        }else{
                            dp[i][j][is_True]=0;
                        }
                    }else{
                        if(is_True==0){
                            dp[i][j][is_True]=1;
                        }
                    }
                    continue;
                }
                long long int ways = 0;
                for (int k = i + 1; k <= j - 1; k += 2)
                {
                    long long int TL = dp[i][k-1][1];
                    long long int TR = dp[k+1][j][1];
                    long long int FL = dp[i][k-1][0];
                    long long int FR = dp[k+1][j][0];
                    if (str[k] == '&')
                    {
                        if (is_True == 1)
                        {
                            ways = ways + TL * TR;
                        }
                        else
                        {
                            ways = ways + TL * FR + FL * FR + FL * TR;
                        }
                    }
                    if (str[k] == '|')
                    {
                        if (is_True == 1)
                        {
                            ways = ways + TL * TR + TL * FR + FL * TR;
                        }
                        else
                        {
                            ways = ways + FL * FR;
                        }
                    }
                    if (str[k] == '^')
                    {
                        if (is_True == 1)
                        {
                            ways = ways + TL * FR + FL * TR;
                        }
                        else
                        {
                            ways = ways + TL * TR + FL * FR;
                        }
                    }
                }
                dp[i][j][is_True] = ways;
            }
        }
    }
    return dp[0][n-1][1];
}

int main()
{
    string str;
    cin >> str;
    int n = str.size();

    cout << "using brute apporach " << endl;
    int brute = brute_apporach(str, 0, n - 1, 1);
    cout << brute << endl;

    cout << "using memorize top down aporach " << endl;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
    int memo = memorize_top_down(str, 0, n - 1, 1, dp);
    cout << memo << endl;

    cout<<"using bottom up apporach "<<endl;
    int bottom=bottom_up_apporach(str);
    cout<<bottom<<endl;
}