#include <bits/stdc++.h>

using namespace std;

int matchingPairs(string s, string t) {
    vector<vector<int>> cnt(26, vector<int>(26, 0));

    int base_match = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        cnt[s[i] - 'a'][t[i] - 'a']++;
        if (s[i] == t[i]) base_match++;
    }

    int best_diff = -2;
    for (int i1 = 0; i1 < 26; i1++) {
        for (int j1 = 0; j1 < 26; j1++) {
            if (cnt[i1][j1] >= 2) best_diff = max(best_diff, 0);
            if (cnt[i1][j1] == 0) continue;

            for (int i2 = 0; i2 < 26; i2++) {
                for (int j2 = 0; j2 < 26; j2++) {
                    if (i1 == i2 && j1 == j2) continue;
                    if (cnt[i2][j2] == 0) continue;

                    int match1 = (i1 == j1) + (i2 == j2);
                    int match2 = (i1 == j2) + (i2 == j1);

                    best_diff = max(best_diff, match2 - match1);
                }
            }
        }
    }

    return base_match + best_diff;
}

