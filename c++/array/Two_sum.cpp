#include <bits/stdc++.h>
using namespace std;
// brute force apporach
//  time complexity is O(n^2)
//  space complexity is O(1)
pair<int, int> two_sum_brute(int n, int arr[], int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                return pair(i, j);
            }
        }
    }
    return pair(-1, -1);
}
// better apporach using hash array but hash map is widely use
// time complexity is  O(n) in the case of hash array
// time complexity is O(nlog(n)) in the case of hash map
// space complexity is O(n)
bool two_sum_better(int n, int arr[], int target)
{
    int index[10 ^ 6];
    for (int i = 0; i < n; i++)
    {
        index[arr[i]] = 1;
    }
    for (int i = 0; i < n; i++)
        {
        if (index[target - arr[i]] == 1)
            {
            return true;
        }
    }
    return false;
}

// optimal apporach
// when given array is sorted we can apply two pointer concept
// time complexity is o(n) if array is already sorted;
// time complexity is O(nlog(n)) if array is not sorted   
// space complexity is o(1);

pair<int, int> two_sum_optimal(int n, int arr[], int target)
{
    int i = 0;
    int j = n - 1;
    int sum = arr[i] + arr[j];
    while (i < j)
    {
        if (sum == target)
        {
            return pair(i, j);
        }
        if (sum < target)
        {
            sum = sum - arr[i];
            i++;
            sum = sum + arr[i];
                }
                else
                {
            sum = sum - arr[j];
            j--;
            sum = sum + arr[j];
        }
    }
    return pair(-1, -1);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cout << "enter a target" << endl;
    cin >> target;

    pair brute = two_sum_brute(n, arr, target);
    cout << brute.first << endl;
    cout << brute.second << endl;

    int better = two_sum_better(n, arr, target);
    cout << better << endl;

    pair optimal = two_sum_optimal(n, arr, target);
    cout << optimal.first << endl;
    cout << optimal.second << endl;
}
