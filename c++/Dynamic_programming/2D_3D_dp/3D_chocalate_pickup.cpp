#include <bits/stdc++.h>
using namespace std;

// brute force apporach
// time compelxity is O()
// space complexity is O(n*m)

// here both alice and joy has fixed intial position
// but other end is veriable
int brute_apporach(vector<vector<int>> &arr, int row, int c1, int c2)
{
    if (c1 < 0 || c2 < 0 || c1 >= arr[0].size() || c2 >= arr[0].size())
    {
        return INT_MIN;
    }
    if (row == arr.size() - 1)
    {
        if (c1 == c2)
        {
            return arr[row][c1];
        }
        else
        {
            return arr[row][c1] + arr[row][c2];
        }
    }
    int maxi = INT_MIN;
    // each have three posibilities
    for (int r1 = -1; r1 <= 1; r1++)
    {
        for (int r2 = -1; r2 <= 1; r2++)
        {
            if (c1 == c2)
            {
                maxi = max(maxi, arr[row][c1] + brute_apporach(arr, row + 1, c1 + r2, c2 + r2));
            }
            else
            {
                maxi = max(maxi, arr[row][c1] + arr[row][c2] + brute_apporach(arr, row + 1, c1 + r1, c2 + r2));
            }
        }
    }
    return maxi;
}

// brute optimal apporach
// time complexiity is O(n*m)
// space complexity is O(n*m)

int brute_optimal(vector<vector<int>> &arr, vector<vector<vector<int>>> &dp, int row, int c1, int c2)
{
    if (c1 < 0 || c2 < 0 || c1 >= arr[0].size() || c2 >= arr[0].size())
    {
        return INT_MIN;
    }
    if (row == arr.size() - 1)
    {
        if (c1 == c2)
        {
            return arr[row][c1];
        }
        else
        {
            return arr[row][c1] + arr[row][c2];
        }
    }
    if (dp[row][c1][c2] != -1)
    {
        return dp[row][c1][c2];
    }
    int maxi = INT_MIN;
    // each have three posibilities
    for (int r1 = -1; r1 <= 1; r1++)
    {
        for (int r2 = -1; r2 <= 1; r2++)
        {
            if (c1 == c2)
            {
                maxi = max(maxi, arr[row][c1] + brute_optimal(arr, dp, row + 1, c1 + r2, c2 + r2));
            }
            else
            {
                maxi = max(maxi, arr[row][c1] + arr[row][c2] + brute_optimal(arr, dp, row + 1, c1 + r1, c2 + r2));
            }
        }
    }
    return dp[row][c1][c2] = maxi;
}

// bottom up apporach
// using different defination of the dp
// time compelxity is O(n*m)
// space complexity is o(n*m)

int bottom_up_apporach(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j< m; j++)
        {
            if (i == j)
            {
                dp[n - 1][i][j] = arr[n - 1][j];
                // cout<<dp[n-1][i][j]<<endl;
            }
            else
            {
                dp[n - 1][i][j] = arr[n - 1][i] + arr[n - 1][j];
                // cout<<dp[n-1][i][j]<<endl;

            }
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = INT_MIN;
                // each have three posibilities
                for (int r1 = -1; r1 <= 1; r1++)
                {
                    for (int r2 = -1; r2 <= 1; r2++)
                    {
                        int value=0;
                        if (j1 == j2)
                        {
                            value=arr[i][j1];
                        }
                        else
                        {
                            value = arr[i][j1] + arr[i][j2];
                        }
                        if(j1+r1>=0 && j1+r1<m && j2+r2>=0 && j2+r2<m ){
                            value+=dp[i+1][j1+r1][j2+r2];
                        }else{
                            value=INT_MIN;
                        }
                        maxi=max(maxi,value);
                        
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m-1];
}

// space optimization
// time compleity is O(n*m)
// space complexity is O(m)

int space_optimization(vector<vector<int>> &arr)
{
   int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> pre(m,vector<int>(m,0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j< m; j++)
        {
            if (i == j)
            {
                pre[i][j] = arr[n - 1][j];
                // cout<<dp[n-1][i][j]<<endl;
            }
            else
            {
                pre[i][j] = arr[n - 1][i] + arr[n - 1][j];
                // cout<<dp[n-1][i][j]<<endl;

            }
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        vector<vector<int>> temp(m,vector<int>(m,0));
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = INT_MIN;
                // each have three posibilities
                for (int r1 = -1; r1 <= 1; r1++)
                {
                    for (int r2 = -1; r2 <= 1; r2++)
                    {
                        int value=0;
                        if (j1 == j2)
                        {
                            value=arr[i][j1];
                        }
                        else
                        {
                            value = arr[i][j1] + arr[i][j2];
                        }
                        if(j1+r1>=0 && j1+r1<m && j2+r2>=0 && j2+r2<m ){
                            value+=pre[j1+r1][j2+r2];
                        }else{
                            value=INT_MIN;
                        }
                        maxi=max(maxi,value);
                        
                    }
                }
                temp[j1][j2] = maxi;
            }
        }
        pre=temp;
    }
    return pre[0][m-1];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "using brute apporach " << endl;
    int brute = brute_apporach(arr, 0, 0, m - 1);
    cout << brute << endl;

    cout << "using brute optimal apporach " << endl;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    int optimal = brute_optimal(arr, dp, 0, 0, m - 1);
    cout << optimal << endl;

    cout<<"using bottom up apporach "<<endl;
    int bottom=bottom_up_apporach(arr);
    cout<<bottom<<endl;

    cout<<"using space optimization"<<endl;
    int space=space_optimization(arr);
    cout<<space<<endl;
}