#include<bits/stdc++.h>

// Created by $%U%$ On $%h%$:$%m%$:$%s%$ on $%D%$-$%M%$-$%Y%$

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

pll operator-(pll p1, pll p2) {
    return pll(p1.first - p2.first, p1.second - p2.second);
}

ll cross(pll p1, pll p2) {
    return p1.first * p2.second - p1.second * p2.first;
}

ll sign(ll x) {
    if (x == 0) return 0;
    if (x < 0) return -1;
    else return +1;
}

bool intersect(pair<pll, pll> f1, pair<pll, pll> f2) {
    ll d11 = cross(f1.second - f1.first, f2.first - f1.first);
    ll d12 = cross(f1.second - f1.first, f2.second - f1.first);

    ll d21 = cross(f2.second - f2.first, f1.first - f2.first);
    ll d22 = cross(f2.second - f2.first, f1.second - f2.first);

    // they co linear
    if (d11 == 0 && d12 == 0) {
        return false;
    }
    if (d21 == 0 && d22 == 0) {
        return false;
    }

    // cout << d11 << " " << d12 << " " << d21 << " " << d22 << endl;

    if (sign(d11) != sign(d12) && sign(d21) != sign(d22)) {
        return true;
    } else {
        return false;
    }
}

bool vis[MAXN];
vector<int> adj[MAXN];

void dfs(int pos) {
    vis[pos] = true;
    for (int i : adj[pos]) {
        if (!vis[i]) {
            dfs(i);
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    vector<pair<pll, pll>> fences;

    for (int i = 0; i < n; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        fences.push_back(make_pair(pll(x1, y1), pll(x2, y2)));
    }

    ll V = 2 * fences.size();
    ll E = fences.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (intersect(fences[i], fences[j])) {
                // cout << i << " intersect " << j << endl;
                adj[i].push_back(j);
                adj[j].push_back(i);
                V++;
                E += 2;
            }
        }
    }

    int K = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
            K++;
        }
    }

    // V - E + F = 1 + K
    // F = 1 + K + E - V
    // exclude the outermost face
    cout << K + E - V;
}
