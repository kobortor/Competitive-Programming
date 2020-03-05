#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<pii> senators;

int n, k, A;

double test() {
    double tot = 0;
    for (int state = 0; state < (1 << n); state++) {
        int B = 0;
        int cnt = 0;
        double prob = 1;
        for (int i = 0; i < n; i++) {
            if (state & (1 << i)) {
                prob *= static_cast<double>(senators[i].second) / 100.0;
                cnt++;
            } else {
                prob *= 1.0 - static_cast<double>(senators[i].second) / 100.0;
                B += senators[i].first;
            }
        }

        if (cnt * 2 > n) {
            tot += prob;
        } else {
            tot += (prob * A) / (A + B);
        }
    }

    return tot;
}

double solve(int idx, int candies) {
    if (idx >= n) {
        return test();
    } else {
        double ans = 0;

        int max_candy = min(candies, (100 - senators[idx].second) / 10);
        for (int i = 0; i <= max_candy; i++) {
            senators[idx].second += i * 10;
            ans = max(ans, solve(idx + 1, candies - i));
            senators[idx].second -= i * 10;
        }

        return ans;
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> k >> A;

    senators = vector<pii>(n);
    for (pii &p : senators) {
        cin >> p.first >> p.second;
    }

    cout << fixed << setprecision(15) << solve(0, k);
}
