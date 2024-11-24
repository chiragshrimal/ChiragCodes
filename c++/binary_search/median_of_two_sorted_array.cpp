#include <bits/stdc++.h>
using namespace std;

// brute force apporach using merging
// time complexity is O(n1+n2)
// space complecity is O(n1+n2)

int median_brute(vector<int> &v1, vector<int> &v2)
{
    int n1 = v1.size();
    int n2 = v2.size();
    vector<int> v3;
    int i = 0;
    int j = 0;
    while (i < n1 && j < n2)
    {
        if (v1[i] <= v2[j])
        {
            v3.push_back(v1[i]);
            i++;
        }
        else
        {
            v3.push_back(v2[j]);
            j++;
        }
    }
    while (i < n1)
    {
        v3.push_back(v1[i]);
        i++;
    }
    while (j < n2)
    {
        v3.push_back(v2[j]);
        j++;
    }

    int n = n1 + n2;
    if (n % 2 == 0)
    {
        return (v3[(n / 2)] + v3[(n / 2) - 1]) / 2;
    }
    else
    {
        return v3[n / 2];
    }
}

// better apporach using cnt variable
// time complexity is O(m+n)
// space complexity is O(1)
int median_better(vector<int> &v1, vector<int> &v2)
{
    int n1 = v1.size();
    int n2 = v2.size();
    int i = 0;
    int j = 0;
    int n = n1 + n2;
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = -1;
    int ele1;
    int ele2;
    while (i < n1 && j < n2)
    {
        if (v1[i] <= v2[j])
        {
            cnt++;
            if (cnt == ind1)
            {
                ele1 = v1[i];
            }
            if (cnt == ind2)
            {
                ele2 = v1[i];
            }
            i++;
        }
        else
        {
            cnt++;
            if (cnt == ind1)
            {
                ele1 = v2[j];
            }
            if (cnt == ind2)
            {
                ele2 = v2[j];
            }
            j++;
        }
    }
    while (i < n1)
    {
        cnt++;
        if (cnt == ind1)
        {
            ele1 = v1[i];
        }
        if (cnt == ind2)
        {
            ele2 = v1[i];
        }
        i++;
    }
    while (j < n2)
    {
        cnt++;
        if (cnt == ind1)
        {
            ele1 = v2[j];
        }
        if (cnt == ind2)
        {
            ele2 = v2[j];
        }
        j++;
    }
    if (n % 2 == 0)
    {
        return (ele1 + ele2) / 2;
    }
    else
    {
        return ele2;
    }
}

// optimal apporach  binary search apply on less element containing  vector
// time complexity is O(log(min(n1,n2)))
// space complecity is o(1)

double median_optimal(vector<int> &v1, vector<int> &v2)
{
    int n1 = v1.size();
    int n2 = v2.size();
    if (n1 > n2)
    {
        return median_optimal(v2, v1);// important point hai return krna hota hain
    }
    int n = n1 + n2;
    int m = (n + 1) / 2;
    int low = 0;
    int high = n1;
    while (low <= high)
    {
        int mid1 = low + ((high - low) >> 1);
        int mid2 = m - mid1;
        int r1 = INT_MAX;
        int r2 = INT_MAX;
        int l1 = INT_MIN;
        int l2 = INT_MIN;
        if (mid1 < n1)
        {
            r1 = v1[mid1];
        }
        if (mid2 < n2)
        {
            r2 = v2[mid2];
        }

        if (mid1 - 1 >= 0)
        {
            l1 = v1[mid1 - 1];
        }

        if (mid2 - 1 >= 0)
        {
            l2 = v2[mid2 - 1];
        }
        if (l1 <= r2 && l2 <= r1)
        {
            if ((n % 2) == 0)
            {
                return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else
            {
                // cout<<max(l1,l2)<<endl;
                return max(l1, l2);
            }
        }

        if (l1 > r2)
        {
            high = mid1 - 1;
        }
        else
        {
            low = mid1 + 1;
        }
    }
    return 0;
}

int main()
{
    int n1;
    cin >> n1;
    int n2;
    cin >> n2;
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < n1; i++)
    {
        int x;
        cin >> x;
        v1.push_back(x);
    }
    for (int j = 0; j < n2; j++)
    {
        int x;
        cin >> x;
        v2.push_back(x);
    }
    // int brute=median_brute(v1,v2);
    // cout<<brute<<endl;

    // int better=median_better(v1,v2);
    // cout<<better<<endl;

    double optimal = median_optimal(v1, v2);
    cout << optimal << endl;
}