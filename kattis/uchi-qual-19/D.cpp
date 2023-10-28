#include <bits/stdc++.h>

using namespace std;

int main () {
    cin.tie(0);
    cin.sync_with_stdio(0);

    while (true) {
        int m;
        cin >> m;
        if (m == 0) break;

        int prev_ht = 0;
        int prev_wid = 0;
        int cur_ht = 0;
        int cur_wid = 0;

        while (true) {
            int x, y;
            cin >> x >> y;
            if (x == -1) {
                break;
            }
            if (cur_wid + x > m) {
                prev_ht += cur_ht;
                prev_wid = max(prev_wid, cur_wid);

                cur_ht = 0;
                cur_wid = 0;
            }

            cur_wid += x;
            cur_ht = max(cur_ht, y);
        }
        prev_ht += cur_ht;
        prev_wid = max(prev_wid, cur_wid);

        cout << prev_wid << " x " << prev_ht << endl;
    }
}
