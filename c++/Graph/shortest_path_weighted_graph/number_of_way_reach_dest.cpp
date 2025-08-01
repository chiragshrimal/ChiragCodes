#include<bits/std++.h>
using namespace std ;

int countPaths(int n, vector<vector<int>> &arr)
{
    long long int mod = 1e9 + 7;
    vector<long long int> dist(n, 1e17);
    int m = arr.size();
    vector<vector<pair<long long, int>>> graph(n);
    for (int i = 0; i < m; i++)
    {
        graph[arr[i][0]].push_back({arr[i][1], arr[i][2]});
        graph[arr[i][1]].push_back({arr[i][0], arr[i][2]});
    }
    dist[0] = 0;
    vector<long long int> ways(n, 0);
    ways[0] = 1;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> minHeap;
    minHeap.push({0, 0});
    while (!minHeap.empty())
    {
        auto f = minHeap.top();
        minHeap.pop();
        int node = f.second;
        long long node_val = f.first;
        for (auto nbr : graph[node])
        {
            int nbr_node = nbr.first;
            long long cur_dist = dist[nbr_node];
            long long nbr_val = nbr.second;
            if (node_val + nbr_val < cur_dist)
            {
                dist[nbr_node] = node_val + nbr_val;
                minHeap.push({dist[nbr_node], nbr_node});
                ways[nbr_node] = (ways[node]) % mod;
            }
            else
            {
                if (node_val + nbr_val == cur_dist)
                {
                    ways[nbr_node] += ways[node];
                    ways[nbr_node] = ways[nbr_node] % mod;
                }
            }
        }
    }
    return ways[n - 1];
}
int main()
{
}