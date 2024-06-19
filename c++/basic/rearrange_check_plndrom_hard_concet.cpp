// t=10
// n=10^5
// q=10^5  given l and r

// soluton
// quries ke under O(1) lgana pdega
//  in palindrom max one character have odd count=1;
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        int hash[26][n];
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < n; j++)
            {
                hash[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            hash[str[i] - 'a'][i]++;
        }
        for (int i = 0; i < 26; i++)
        {
            for (int j = 1; j < n; j++)
            {
                hash[i][j] = hash[i][j] + hash[i][j - 1];
            }
        }
        int q;
        cin >> q;
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            int total_odd = 0;
            for (int i = 0; i < 26; i++)
            {
                int count = 0;
                if (l == 0)
                {
                    count = hash[i][r];
                }
                else
                    count = hash[i][r] - hash[i][l - 1];
                if (count != 1 && count % 2 != 0)
                {
                    cout << "no" << endl;
                    break;
                }
                else
                {
                    if (count == 1)
                    {
                        total_odd++;
                    }
                }
            }
            if (total_odd > 1)
                cout << "no" << endl;
            else
            {
                cout << "yes" << endl;
            }
        }
    }
}
