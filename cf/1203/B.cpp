#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int cnt[10005];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        memset(cnt, 0, sizeof cnt);
        for (int a = 0, x; a < 4 * n; a++) {
            cin >> x;
            cnt[x]++;
        }

        deque<int> lengths;
        bool good = true;
        for (int a = 0; a < 10005; a++) {
            if (cnt[a] % 2) {
                good = false;
                break;
            } else {
                while (cnt[a]) {
                    lengths.push_back(a);
                    cnt[a] -= 2;
                }
            }
        }

        if (!good) {
            cout << "NO\n";
            continue;
        }

        sort(allof(lengths));

        vector<int> areas;
        while (!lengths.empty()) {
            areas.push_back(lengths.front() * lengths.back());
            lengths.pop_front();
            lengths.pop_back();
        }

        for (int a = 1; a < (int)areas.size(); a++) {
            if (areas[a] != areas[a - 1]) {
                good = false;
                break;
            }
        }

        if (good) cout << "YES\n";
        else cout << "NO\n";
    }
}
