#include <bits/stdc++.h>
using namespace std;
// brute force apporach
// time complexity is O(n^2)
// space complexity is O(n)

vector<int> leader_brute(vector<int> v)
{
    vector<int> ans;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] < v[j])
            {
                flag++;
                break;
            }
        }
        if (flag == 0)
        {
            ans.push_back(v[i]);
        }
    }
    return ans;
}
// optimal apporach 
// time complexity is O(n);
// space complexity is O(n);
vector<int> leader_optimal(vector<int> v){
    vector<int> ans;
    int n=v.size();
    int leader=v[n-1];
    ans.push_back(v[n-1]);
    for(int i=n-2;i>=0;i--){
        if(v[i]>leader){
            leader=v[i];
            ans.push_back(v[i]);
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int > brute=leader_brute(v);
    vector<int > optimal=leader_optimal(v);
    for(auto it: brute){
        cout<<it<<endl;
    }
      for(auto it: optimal){
        cout<<it<<endl;
    }
}