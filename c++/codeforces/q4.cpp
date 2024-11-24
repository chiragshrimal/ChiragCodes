#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        string str;
        cin >> str;

        vector<long int> presum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            presum[i + 1] = presum[i] + v[i];
        }

        long int maxi = 0;
        int i = 0;
        int j = n - 1;

        while (i < j) {
            if (str[i] == 'L' && str[j] == 'R') {
                maxi += presum[j + 1] - presum[i];
                i++;
                j--;
            } else {
                while (i < n && str[i] != 'L') {
                    i++;
                }
                while (j >= 0 && str[j] != 'R') {
                    j--;
                }
            }
        }
        cout << maxi << endl;
    }
    return 0;
}
