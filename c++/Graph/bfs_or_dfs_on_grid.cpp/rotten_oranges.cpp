#include <bits/stdc++.h>
using namespace std;

// time complexity is O(n*m)
// space complexity is O(1)
int solve(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    // vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 2)
            {
                q.push(pair(i, j));
                // visited[i][j]=1;
            }
        }
    }
    int time = 0;
    vector<int> row(4, 0);
    vector<int> col(4, 0);
    row[0] = -1;
    row[2] = 1;
    col[1] = 1;
    col[3] = -1;
    while (!q.empty())
    {
        int temp = 0;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int x = q.front().first;
            int y = q.front().second;
            arr[x][y] = 2;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int r1 = x + row[i];
                int r2 = y + col[i];
                if (r1 < n && r2 < m && r1 >= 0 && r2 >= 0 && arr[r1][r2] == 1)
                {
                    temp = 1;
                    q.push(pair(r1, r2));
                    arr[r1][r2] = 2;
                }
            }
        }
        time+=temp;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                return -1;
            }
        }
    }
    return time;
}
int main()
{
    int n;
    int m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << solve(grid) << endl;
}