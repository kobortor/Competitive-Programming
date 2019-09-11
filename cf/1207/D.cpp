#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 998244353;
const int MAXN = 3e5 + 5;

ll fact[MAXN];

template <class T>
ll getf (vector<T> v) {
    sort(allof(v));
    int idx = 0;
    ll ans = 1;

    while (idx < (int)v.size()) {
        int nxt = idx + 1;
        while (nxt < (int)v.size() && v[nxt] == v[idx]) nxt++;

        ans = ans * fact[nxt - idx] % mod;
        idx = nxt;
    }
    return ans;
}

bool cone (vector<pii> &v) {
    for (int a = 1; a < (int)v.size(); a++) {
        if (v[a].second < v[a - 1].second) return false;
    }
    return true;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    fact[0] = 1;
    for (int a = 1; a < MAXN; a++) {
        fact[a] = fact[a - 1] * a % mod;
    }

    int n;
    cin >> n;

    vector<pii> v(n);
    vector<int> fst, snd;
    for (pii &p : v) {
        cin >> p.first >> p.second;
        fst.push_back(p.first);
        snd.push_back(p.second);
    }

    sort(allof(v));
    sort(allof(fst));
    sort(allof(snd));

    ll num_inc = getf(fst);
    ll num_dec = getf(snd);
    ll num_both = cone(v) ? getf(v) : 0ll;

    ll num_bad = ((num_inc + num_dec - num_both) % mod + mod) % mod;
    ll num_tot = fact[n];
    cout << (num_tot - num_bad + mod) % mod;
}
