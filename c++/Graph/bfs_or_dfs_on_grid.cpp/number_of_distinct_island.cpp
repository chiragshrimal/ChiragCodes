#include <bits/stdc++.h>
using namespace std;

// using bfs
// time complexity is o()
// space complexity is O()
struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ hash<int>()(p.second << 1);
    }
};

int Count_island(vector<vector<int>>&arr)
{
    int n = arr.size();
    int m = arr[0].size();
    unordered_map<pair<int,int>,int, pair_hash> map;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    int cnt = 0;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0 && arr[i][j] == 1)
            {
                int min_row=INT_MAX;
                int min_col=INT_MAX;
                int max_row=INT_MIN;
                int max_col=INT_MIN;
                q.push({i, j});
                visited[i][j] = 1;
                int one=0;
                while (!q.empty())
                {
                    auto f = q.front();
                    int r = f.first;
                    int c = f.second;
                    one++;
                    min_row=min(min_row,r);
                    min_col=min(min_col,c);
                    max_row=max(max_row,r);
                    max_col=max(max_col,c);
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int row = r + dx[k];
                        int col = c + dy[k];
                        if (row >= 0 && col >= 0 && row < n && col < m)
                        {
                            if (arr[row][col] == 1 && visited[row][col] == 0)
                            {
                                q.push({row, col});
                                visited[row][col] = 1;
                            }
                        }
                    }
                }
                map[{max_row-min_row+1,max_col-min_col+1}]=one;
            }
        }
    }
    return map.size();
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
    int ans=Count_island(arr);
    cout<<ans<<endl;
}