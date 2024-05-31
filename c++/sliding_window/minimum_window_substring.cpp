#include <bits/stdc++.h>
using namespace std;
// brute force apporach 1;
// time complexity is O(n^2*m)
// space complexity is O(n)
string minimum_window_substring_brute1(string s, string t)
{
    int nt = t.size();
    int ns = s.size();
    int minlength = INT_MAX;
    string ans = "";
    unordered_map<char, int> T;
    for (int i = 0; i < nt; i++)
    {
        T[t[i]]++;
    }
    for (int i = 0; i < ns; i++)
    {
        unordered_map<char, int> temp(T.begin(), T.end());
        string str = "";
        for (int j = i; j < ns; j++)
        {
            str = str + s[j];
            if (temp.find(s[j]) != temp.end())
            {
                temp[s[j]]--;
                if (temp[s[j]] == 0)
                {
                    temp.erase(s[j]);
                }
            }
            if (temp.size() == 0)
            {
                if (minlength > j - i + 1)
                {
                    ans = str;
                    minlength = j - i + 1;
                    break;
                }
            }
        }
    }
    return ans;
}
// brute force apporach striver
// time complexity is O(n^2*m)
// space complexity is O(256)
string minimum_window_substring_brute2(string s, string t)
{
    int n = s.size();
    int m = t.size();
    int minlength = INT_MAX;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        int hash[256] = {0};
        int count = 0;
        for (int k = 0; k < m; k++)
        {
            hash[t[k] - 'A']++;
        }
        for (int j = i; j < n; j++)
        {
            if (hash[s[j] - 'A'] > 0)
            {
                count++;
            }
            hash[s[j] - 'A']--;
            if (count == m)
            {
                if (minlength > j - i + 1)
                {
                    minlength = j - i + 1;
                    index = i;
                }
                break;
            }
        }
    }
    string ans = "";
    if (index != -1)
    {
        for (int k = index; k < index + minlength; k++)
        {
            ans = ans + s[k];
        }
    }
    return ans;
}
// optimal apporach
// time complexity is O()
// space complexity is O()
string minimum_window_substring_optimal(string s, string t)
{
    int n = s.size();
    int m = t.size();
    int minlength = INT_MAX;
    int index = -1;
    int count = 0;
    int hash[256] = {0};
    for (int i = 0; i < m; i++)
    {
        hash[t[i] - 'A']++;
    }
    int i = 0;
    int j = 0;
    while (j < n)
    {
        if (hash[s[j] - 'A'] > 0)
        {
            count++;
        }
        hash[s[j] - 'A']--;
        while (count == m)
        {
            minlength = min(minlength, j - i + 1);
            index = i;
            hash[s[i] - 'A']++;
            if (hash[s[i] - 'A'] > 0)
            {
                count--;
            }
            i++;
        }
        j++;
    }
    string ans = "";
    if (index != -1)
    {
        for (int i = index; i < index + minlength; i++)
        {
            ans = ans + s[i];
        }
    }

    return ans;
}

int main()
{
    string s;
    cin >> s;
    string t;
    cin >> t;
    string brute1 = minimum_window_substring_brute1(s, t);
    cout << brute1 << endl;
    string brute2 = minimum_window_substring_brute2(s, t);
    cout << brute2 << endl;
    string optimal=minimum_window_substring_optimal(s,t);
    cout<<optimal<<endl;
}