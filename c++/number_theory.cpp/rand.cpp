#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int h;
        long long int x;
        long long int y1;
        long long int y2;
        long long int k;
        cin >> h;
        cin >> x;
        cin >> y1;
        cin >> y2;
        cin >> k;
        int count1 = 0;
        if ((h % x) != 0)
        {
            count1 = h / x + 1;
        }
        else
        {
            count1 = h / x;
        }
        int count2 = 0;
        int m = 0;
        if ((h % y1) != 0)
        {
            m = h / y1 + 1;
            if (m <= k)
            {
                count2 = m;
            }
            else
            {
                if ((h - y1 * k) % m == 0){
                    count2 = k + (h - y1 * k) / m;
                }
                else
                {
                    count2 = k + (h - y1 * k) / m + 1;
                }
            }
        }
        else
        {
            m = h / y1;
            if (m <= k)
            {
                count2 = m;
            }
            else
            {
                if (((h - y1 * k) % m )== 0){
                    count2 = k + (h - y1 * k) / m;
                    }
                else
                {
                    count2 = k + (h - y1 * k) / m + 1;
                }
            }
            cout << min(count1, count2) << endl;
        }
    }
}