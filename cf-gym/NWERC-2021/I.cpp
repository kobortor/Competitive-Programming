#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// ll M, D, C, L, X, V, I;

// I V X L C D M
string chars = "IVXLCDM";
ll cnt[7];
ll jmp[7];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    for (int i = 6; i >= 0; i--) {
        cin >> cnt[i];
    }

    while (*max_element(cnt, cnt + 7) != 0) {
        ll max_steps = LLONG_MAX;
        string s;
        for (int i = 6; i >= 0; i--) {
            if (cnt[i] == 0) continue;

            if (i % 2 == 1) {
                // 5s
                jmp[i] = 1;
                max_steps = min(max_steps, cnt[i]);
            } else {
                // 1s
                jmp[i] = min(3ll, cnt[i]);
                max_steps = min(max_steps, (cnt[i] + jmp[i] - 1) / jmp[i]);
            }

            // cout << "Add " << chars[i] << " " << jmp[i] << " times\n";
            for (int j = 0; j < jmp[i]; j++) {
                s += chars[i];
            }
        }

        cout << s << " " << max_steps << endl;
        for (int i = 0; i < 7; i++) {
            cnt[i] -= jmp[i] * max_steps;
            cout << cnt[i] << " ";
        }
        cout << endl;
    }

    // cout << ans << "\n";
}