#include <bits/stdc++.h>
using namespace std;

// using bfs
// time complexity is o(n*m)
// space complexity is O(n*m)

int Count_island(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    int cnt = 0;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0 && arr[i][j] == '1')
            {
                q.push({i, j});
                visited[i][j] = 1;
                while (!q.empty())
                {
                    auto f = q.front();
                    int r = f.first;
                    int c = f.second;
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int row = r + dx[k];
                        int col = c + dy[k];
                        if (row >= 0 && col >= 0 && row < n && col < m)
                        {
                            if (arr[row][col] == '1' && visited[row][col] == 0)
                            {
                                q.push({row, col});
                                visited[row][col] = 1;
                            }
                        }
                    }
                }
                cnt++;
            }
        }
    }
    return cnt;
}

// space optimization
// time complexity is O()
// space complexity is O()

int space_opti(vector<vector<int>>&arr)
{
    int n = arr.size();
    int m = arr[0].size();
    // vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    int cnt = 0;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                q.push({i, j});
                while (!q.empty())
                {
                    auto f = q.front();
                    int r = f.first;
                    int c = f.second;
                    arr[r][c]=0;
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int row = r + dx[k];
                        int col = c + dy[k];
                        if (row >= 0 && col >= 0 && row < n && col < m)
                        {
                            if (arr[row][col] == 1)
                            {
                                q.push({row, col});
                                // because visited wali chiz satisfy krani hai 
                                arr[roe][col]=0;
                            }
                        }
                    }
                }
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
     int m,n;
    cin>>m>>n;
    vector<vector<int>> arr(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int ans=space_opti(arr);
    cout<<ans<<endl;
}