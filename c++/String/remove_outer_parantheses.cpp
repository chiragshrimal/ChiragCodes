class Solution
{
public:
    string removeOuterParentheses(string str)
    {
        int n = str.size();
        if (n == 0)
        {
            return "";
        }
        stack<int> s;
        int start = 0;
        int end = 0;
        s.push(str[0]);
        set<int> v;
        for (int i = 1; i < n; i++)
        {
            end = i;
            if (s.empty())
            {
                s.push(str[end]);
            }
            else
            {
                if (s.top() == '(' && str[end] == ')' || s.top() == ')' && str[end] == '(')
                {
                    s.pop();
                }
                else
                {
                    s.push(str[end]);
                }
                if (s.empty() && start != n)
                {
                    v.insert(start);
                    v.insert(end);
                    start = end + 1;
                }
            }
        }
        string ans;
        for (int i = 0; i < n; i++)
        {
            if (v.find(i) == v.end())
            {
                ans.push_back(str[i]);
            }
        }
        return ans;
    }
};