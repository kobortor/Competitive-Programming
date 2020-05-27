#include<bits/stdc++.h>

// Created by kobortor On 00:42:08 on 27-05-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> factors[200005];

ll ipow(ll x, ll y) {
    return y == 0 ? 1 : x * ipow(x, y - 1);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n;
    cin >> n;

    for (ll t = 0; t < n; t++) {
        ll ai;
        cin >> ai;

        map<ll, ll> mp;
        for (ll i = 2; i * i <= ai; i++) {
            while (ai % i == 0) {
                mp[i]++;
                ai /= i;
            }
        }
        if (ai != 1) mp[ai]++;

        for (pll p : mp) {
            factors[p.first].push_back(p.second);
        }
    }

    ll ans = 1;
    for (ll i = 1; i < 200005; i++) {
        sort(allof(factors[i]));
        if ((ll)factors[i].size() == n) {
            ans *= ipow(i, factors[i][1]);
        } else if ((ll)factors[i].size() == n - 1) {
            ans *= ipow(i, factors[i][0]);
        }
    }

    cout << ans;
}
