#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct target {
    int x, y, t;
    double p;
    bool operator<(const target &t) const {
        return this->t < t.t;
    }
};


int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    vector<target> targets(n);
    for (target &t : targets) {
        cin >> t.x >> t.y >> t.t >> t.p;
    }

    sort(allof(targets));

    vector<double> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = targets[i].p;
        for (int j = 0; j < i; j++) {
            int dx = targets[i].x - targets[j].x;
            int dy = targets[i].y - targets[j].y;
            ll dt = targets[i].t - targets[j].t;
            if (dx * dx + dy * dy <= dt * dt) {
                dp[i] = max(dp[i], targets[i].p + dp[j]);
            }
        }
    }

    cout << fixed << setprecision(15) << *max_element(allof(dp));
}
