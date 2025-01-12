#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;  // number of test cases
    cin >> T;

    for (int caseN = 1; caseN <= T; ++caseN) {
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> flowerbeds(n);

        for (int i = 0; i < n; ++i) {
            cin >> flowerbeds[i].first >> flowerbeds[i].second;
        }

        int totalWaterings = 0;

        for (const auto& bed : flowerbeds) {
            int a = bed.first;

            int b = bed.second;

            int nextWateringDay = 0;
            int waterCount = 0;

            while (nextWateringDay + a <= k) {
                nextWateringDay += a;
                if (nextWateringDay <= k) {
                    ++waterCount;
                }
            }

            totalWaterings += waterCount;
        }

        cout << "Case " << caseN << ": " << totalWaterings << endl;
    }

    return 0;
}
