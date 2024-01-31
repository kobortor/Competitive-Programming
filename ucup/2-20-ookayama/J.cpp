#include "bits/stdc++.h"

using namespace std;

#define ll long long

set<ll> solve(int n, int m) {
    set<ll> ans;
    ans.insert(0);
    ans.insert((1ll << n) - 1);

    if (m == 2) return ans;

    if (n == 2 && m == 2) {
        return ans;
    }
    if (n == 2 && m == 3) {
        ans.insert(1);
        return ans;
    }
    if (n == 3 && m == 5) {
        ans.insert(1);
        ans.insert(2);
        ans.insert(3);
        return ans;
    }
    if (n == 4 && m == 9) {
        ans.insert(1);
        ans.insert(2);
        ans.insert(3);
        ans.insert(4);
        ans.insert(5);
        ans.insert(6);
        ans.insert(7);
        return ans;
    }
    if (n == 5 && m == 15) {
        ans.insert(0);
        ans.insert(1);
        ans.insert(2);
        ans.insert(3);
        ans.insert(4);
        ans.insert(5);
        ans.insert(6);
        ans.insert(7);
        ans.insert(9);
        ans.insert(11);
        ans.insert(13);
        ans.insert(15);
        ans.insert(22);
        ans.insert(23);
        ans.insert(31);
        return ans;
    }

    if (m % 2) {
        ans = solve(n - 1, m - 1);
        ans.insert((1ll << n) - 1);
        return ans;
    }

    ans = solve(n - 1, m / 2);
    set<ll> aux;
    for (ll x : ans) {
        aux.insert(x ^ (1ll << (n - 1)));
    }
    for (ll x : aux) ans.insert(x);

    return ans;
}

int check(int n, int m, set<ll> cur) {
    if (cur.size() != m || !cur.count(0) || !cur.count((1ll << n) - 1)) {
        return 0;
    }

    for (ll x : cur) {
        for (ll y : cur) {
            if (!cur.count(x & y) || !cur.count(x | y)) {
                return 0;
            }
        }
    }
    return 1;
}

int cntr = 0;
void gen(int n, int m, set<ll> &sf) {
    if (sf.size() + 1 == m) {
        sf.insert((1 << n) - 1);
        if (check(n, m, sf)) {
            for (int x : sf) {
                cout << "ans.insert(" << x << ");\n";
            }
            cout << endl;
            exit(0);
        } else {
            cout << (++cntr) << " bad checked\n";
        }
        sf.erase((1 << n) - 1);
        return;
    }

    int lv = (sf.size() ? ((*sf.rbegin()) + 1) : 0);
    for (int i = lv; i + 1 < (1 << n); i++) {
        sf.insert(i);
        gen(n, m, sf);
        sf.erase(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;

        set<ll> cur = solve(n, m);

        for (ll x : cur) cout << x << " ";
        cout << "\n";
    }
}
