#include <bits/stdc++.h>
using namespace std;
// N<=10^6
// Q<= 10^6
const int N = 1e6 + 10;
int a[N];
int hp[N];
int b[N];
vector<int> prime_divisor(int x)
{ // o(log(n))
    vector<int> ans;
    while (x > 1)
    {
        int high = hp[x];
        while ((x % high) == 0)
        {
            x = x / high;
        }
        ans.push_back(high);
    }
    return ans;
}
int main()
{
    for (int i = 2; i < N; i++)
    {
        if (hp[i] == 0)
        {
            hp[i] = i;
            for (int j = 2 * i; j < N; j++)
            {
                hp[j] = i;
            }
        }
    }
    int n;
    cin >> n;
    int q;
    cin >> q;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 2; i < N; i++)
    {
        if (a[i] != 0)
        {
            for (int j = i; j < N; j *= i)
            {
                b[j] = 1;
            }
        }
    }
    while (q--)
    {
        int x;
        cin >> x;
        vector<int> v = prime_divisor(x);
        bool check = false;
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = i + 1; j < v.size(); j++)
            {
                int product = v[i] * v[j];
                if (b[x / product] == 1 && x % product == 0)
                {
                    cout << "yes" << endl;
                    check = true;
                    break;
                }
            }
            if (check == true)
            {
                break;
            }
        }
        if (check == false)
        {
            cout << "no" << endl;
        }
    }
}