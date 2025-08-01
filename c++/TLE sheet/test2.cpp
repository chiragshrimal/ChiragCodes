#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<int> freq(n + 1, 0);
        for (int x : a) {
            fre[x]++;
        }
        
        vector<int> diff(n + 2, 0);
        
        int prefixExtra = 0;
        int suffixTotal = 0; 
        
        for (int i = 1; i <= n; i++) {
            suffixTotal += freq[i];
        }
        for (int m = 0; m <= n; m++) {
            bool possible = true;
            for (int i = 0; i < m; i++) {
                if (freq[i] == 0) {
                    possible = false;
                    break;
                }
            }
            
            if (!possible) {
                if (m < n) {
                    prefixExtra += max(0, freq[m] - 1);
                    suffixTotal -= freq[m + 1];
                }
                continue;
            }
            
            int minK = freq[m];
            int maxK = prefixExtra + freq[m] + suffixTotal;
            if (minK <= n) {
                diff[minK]++;
                diff[min(maxK, n) + 1]--;
            }
            if (m < n) {
                prefixExtra += max(0, freq[m] - 1);
                suffixTotal -= freq[m + 1];
            }
        }

        vector<int> result(n + 1, 0);
        for (int k = 0; k <= n; k++) {
            if (k == 0) {
                result[k] = diff[k];
            } else {
                result[k] = result[k - 1] + diff[k];
            }
        }
        for (int k = 0; k <= n; k++) {
            cout << result[k];
            if (k < n) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}