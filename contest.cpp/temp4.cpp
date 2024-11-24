class Solution
{
public:
    int numberOfSubstrings(string s, int k)
    {
        unordered_map<int, int> m;
        int n = s.size();
        int cnt = 0;
        int cnt = 0;
        int store = 0;
        int i = 0;
        int j = 0;
        while (i <= j && j < n)
        {
            if (store > 0)
            {
                cnt = cnt + n - j;
                m[s[i]]--;
                if (m[s[i]] == k - 1)
                {
                    store--;
                }
                i++;
            }
            else
            {
                j++;
                if (j < n)
                {
                    if (m.find(s[j]) == m.end())
                    {
                        m[s[j]]++;
                        if (m[s[j]] >= k)
                        {
                            store++;
                        }
                    }
                    else
                    {
                        m[s[j]]++;
                        if (m[s[j]] >= k)
                        {
                            store++;
                        }
                    }
                }
            }
        }
    };