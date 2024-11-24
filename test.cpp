#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number of swaps to make the permutation simple
int minSwapsToSimple(vector<int>& p, int n) {
    vector<bool> visited(n + 1, false); // To mark if a position is already visited
    int swaps = 0;
    bool has_2_cycle = false; // To check if we have a 2-cycle

    // Traverse through each element in the permutation
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int cycle_len = 0;
            int x = i;

            // Detect the cycle that starts from element i
            while (!visited[x]) {
                visited[x] = true;
                x = p[x];
                cycle_len++;
            }

            // If the cycle length is greater than 1, we need to process it
            if (cycle_len > 1) {
                // If cycle length is exactly 2, mark the presence of a 2-cycle
                if (cycle_len == 2) {
                    has_2_cycle = true;
                } else {
                    // For a cycle of length > 2, we need at least 1 swap to simplify it
                    swaps++;
                }
            }
        }
    }

    // If there was at least one 2-cycle, and we didn't need to swap any longer cycle
    if (swaps == 0 && has_2_cycle) {
        // Perform one swap to reduce a cycle
        swaps++;
    }

    return swaps;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n + 1);  // Permutation is 1-based

        // Input the permutation p
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }

        // Find the minimal number of swaps required to make the permutation simple
        int result = minSwapsToSimple(p, n);
        cout << result << endl;
    }

    return 0;
}
