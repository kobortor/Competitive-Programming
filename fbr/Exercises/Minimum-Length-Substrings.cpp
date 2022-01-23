#include <bits/stdc++.h>

using namespace std;

int minLengthSubstring(string s, string t) {
    array<int, 26> counts;
    fill(counts.begin(), counts.end(), 0);

    for (char c : t) counts[c - 'a']--;

    int bad = 0;
    for (int cnt : counts) {
        if (cnt < 0) {
            bad++;
        }
    }

    int answer = INT_MAX;
    for (int i = 0, j = 0; i < (int)s.size(); i++) {
        counts[s[i] - 'a']++;

        if (counts[s[i] - 'a'] == 0) {
            bad--;
        }

        if (bad == 0) {
            while (counts[s[j] - 'a'] > 0) {
                counts[s[j++] - 'a']--;
            }
            answer = min(answer, i - j + 1);
        }
    }

    if (answer == INT_MAX) return -1;
    else return answer;
}
