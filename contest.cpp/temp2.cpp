#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << endl

int compareInfection(pair<int,int> virus, pair<int,int> bacteria) {
    return virus.first + virus.second < bacteria.first + bacteria.second;
}

void spreadPlague() {
    int infectionCount;
    cin >> infectionCount;
    vector<pair<int,int>> pathogenStrains(infectionCount);
    for (int i = 0; i < infectionCount; i++) {
        cin >> pathogenStrains[i].first;
        cin >> pathogenStrains[i].second;
    }
    sort(pathogenStrains.begin(), pathogenStrains.end(), compareInfection);
    for (int i = 0; i < infectionCount; i++) {
        if (i != infectionCount - 1)
            cout << pathogenStrains[i].first << " " << pathogenStrains[i].second << " ";
        else
            cout << pathogenStrains[i].first << " " << pathogenStrains[i].second;
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int epidemicWaves = 1;
    cin >> epidemicWaves;
    for (int i = 1; i <= epidemicWaves; ++i) {
        spreadPlague();
    }

    return 0;
}