#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int photo_cnt = 0;
    while (true) {
        photo_cnt++;

        int n;
        cin >> n;
        if (n == 0) break;

        vector<pll> points;
        for (int i = 0; i < n; i++) {
            pll p;
            cin >> p.first >> p.second;
            points.push_back(p);
        }
        
        map<ll, ll> y_counts;
        for (pll p : points) {
            y_counts[p.second]++;
        }

        ll answer = 0;
        for (pll p : y_counts) {
            answer = max(answer, p.second);
        }

        for (pll p : points) {
            // cout << "Check out " << p.first << " " << p.second << endl;
            map<pll, ll> slope_counts;
            for (pll q : points) {
                ll dx = q.first - p.first;
                ll dy = q.second - p.second;
                if (dx <= 0) continue;

                ll g = __gcd(dx, dy);
                dx /= g;
                dy /= g;

                slope_counts[pll(dx, dy)]++;
            }

            for (auto au : slope_counts) {
                // cout << au.first.first << " " << au.first.second << " takes " << au.second << endl;
                answer = max(answer, au.second + 1);
            }
        }

        if (answer < 4) {
            answer = 0;
        }
        cout << "Photo " << photo_cnt << ": " << answer << " points eliminated\n";
    }
}