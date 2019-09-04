#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    vector<pll> v(N);
    for (pll &p : v) cin >> p.first >> p.second;
    v.push_back({0, 0});

    sort(allof(v));

    ll loc = 0;
    ll ans = LLONG_MAX;

    ll lft = 0, rht = 0;
    ll cur = 0;
    for (int a = 1; a <= N; a++) {
        rht += v[a].second;
        cur += v[a].second * v[a].first;
    }

    for (int a = 1; a <= N; a++) {
        cur += lft * (v[a].first - v[a - 1].first);
        cur -= rht * (v[a].first - v[a - 1].first);

        if (cur < ans) {
            ans = cur;
            loc = v[a].first;
        }

        rht -= v[a].second;
        lft += v[a].second;
    }

    cout << loc;
}
