#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subset;

void generate(vector<int> v, int i, int current_sum, int sum, vector<int> nums)
{
    if (current_sum == sum)
    {
        subset.push_back(v);
        return;
    }
    if (i == nums.size())
    {
        return;
    }
    if (current_sum < sum)
    {
        generate(v, i + 1, current_sum, sum, nums);
        v.push_back(nums[i]);
        generate(v, i + 1, current_sum + nums[i], sum, nums);
        v.pop_back(); 
    }
    else
    {
        return;
    }
}
int main()
{
    int n;
    cin >> n;
    int sum;
    cin>>sum;
    vector<int> nums;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    vector<int>empty;
    generate(empty,0,0,sum,nums);
    for (auto value : subset)
    {
        for (auto ele : value)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}