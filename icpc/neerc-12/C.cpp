#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll ggcd(ll x, ll y) {
    if (!x) return y;
    if (!y) return x;
    return ggcd(y%x, x);
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    freopen("caravan.in", "r", stdin);
    freopen("caravan.out", "w", stdout);

    int n; cin >> n;

    vector<pair<int,int>> a(n);
    for (auto &[x, y] : a) {
        cin >> x >> y;
    }

    sort(a.begin(), a.end());

    int lo = 0, hi = 1e9;
    while (lo != hi) {
        
        int avg = (lo + hi + 1) / 2;

        int sf = -1e9;
        int ok = 1;
        for (auto [x, y] : a) {
            int cl = max(x, sf);
            if (cl + avg > y) {
                ok = 0;
                break;
            }
            sf = cl + avg;
        }

        if (ok) lo = avg;
        else hi = avg - 1;

    }

    vector<int> tl;
    int sf = -1e9;
    for (auto [x, y] : a) {
        int cl = max(x, sf);
        tl.push_back(cl);
        sf = cl + lo;
    }

    pair<ll,ll> best = {1, 1};
    int lv = 0;
    for (int i = 0; i < n; i++) {
        auto [l, r] = a[i];

        if (i && tl[i] > tl[i - 1] + lo) {
            lv = i;
        }

        pair<ll,ll> dnxt = {a[i].second - (tl[i] + lo), i - lv + 1};

        if (dnxt.first * best.second < dnxt.second * best.first) 
            best = dnxt;

    }

    best.first += (best.second * ((ll)lo));

    ll gg = ggcd(best.first, best.second);

    cout << (best.first / gg) << "/" << (best.second / gg) << "\n";

}
