#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll dist(pll p) {
    return p.first * p.first + p.second * p.second;
}

const int MAXN = 1e5 + 5;
pll stars[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    for (int a = 1; a <= n; a++) {
        cin >> stars[a].first >> stars[a].second;
    }

    for (int a = n; a >= 1; a--) {
        stars[a].first -= stars[1].first;
        stars[a].second -= stars[1].second;
    }

    ll bestdist = dist(stars[2]);
    int neigh = 2;
    for (int a = 3; a <= n; a++) {
        ll d = dist(stars[a]);
        if (d < bestdist) {
            bestdist = d;
            neigh = a;
        }
    }

    bestdist = LLONG_MAX;
    int best = -1;
    for (int a = 2; a <= n; a++) {
        if (a == neigh) {
            continue;
        }

        ll Ax = stars[neigh].first;
        ll Ay = stars[neigh].second;
        
        ll Bx = stars[a].first;
        ll By = stars[a].second;

        ll ortho = abs(Ax * By - Ay * Bx);
        if (ortho == 0) continue;
        if (ortho < bestdist) {
            bestdist = ortho;
            best = a;
        }
    }

    cout << 1 << " " << neigh << " " << best;
}
