#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
int min_prime[MAX_N]; // minimal prime factor

// Sieve to precompute minimal prime factors
void build_sieve() {
    for (int i = 2; i < MAX_N; i++) {
        if (min_prime[i] == 0) {
            for (int j = i; j < MAX_N; j += i) {
                if (min_prime[j] == 0) {
                    min_prime[j] = i;
                }
            }
        }
    }
}

void solve_case(int n) {
    vector<vector<int>> groups(MAX_N);

    // Build groups by minimal prime factor
    for (int i = 2; i <= n; i++) {
        groups[min_prime[i]].push_back(i);
    }

    vector<int> p(n + 1, 0);
    p[1] = 1;  // we keep p[1]=1

    // For each group, rotate and assign
    for (int i = 2; i <= n; i++) {
        if (!groups[i].empty()) {
            auto &group = groups[i];
            int sz = group.size();
            for (int j = 0; j < sz; j++) {
                int current = group[j];
                int next = group[(j + 1) % sz];
                p[current] = next;
            }
            group.clear(); // clear to reuse for next test case
        }
    }

    // Output
    for (int i = 1; i <= n; i++) {
        cout << p[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    build_sieve(); // preprocess sieve once

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve_case(n);
    }
    return 0;
}
