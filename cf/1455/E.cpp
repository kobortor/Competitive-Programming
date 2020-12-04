#include<bits/stdc++.h>

// Created by kobortor On 01:26:04 on 04-12-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


struct point {
    ll x, y;
    point () : x(0), y(0) {}
    point (ll _x, ll _y) : x(_x), y(_y) {}
};

istream& operator>> (istream& in, point &p) {
    return in >> p.x >> p.y;
}

ostream& operator<< (ostream& out, const point &p) {
    return out << "(" << p.x << " " << p.y << ")";
}

bool operator<(const point &p1, const point &p2) {
    if (p1.x == p2.x) {
        return p1.y < p2.y;
    } else {
        return p1.x < p2.x;
    }
}

/*
2-3
|.|
1-4
*/

ll get_cost(point p1, point p2, point p3, point p4) {
    vector<ll> xs = {p1.x, p2.x, p3.x, p4.x};
    vector<ll> ys = {p1.y, p2.y, p3.y, p4.y};

    nth_element(xs.begin(), xs.begin() + 1, xs.end());
    nth_element(ys.begin(), ys.begin() + 1, ys.end());

    ll x = xs[1];
    ll y = ys[1];

    ll ans = 0;
    for (ll &xi : xs) ans += abs(xi - x);
    for (ll &yi : ys) ans += abs(yi - y);

    return ans;
}

ll solve(point p1, point p2, point p3, point p4) {
    ll ans = get_cost(p1, p2, p3, p4);

    vector<ll> ks;
    ks.reserve(8);

    ks.push_back(p3.x - p1.x);
    ks.push_back(p4.x - p1.x);
    ks.push_back(p3.x - p2.x);
    ks.push_back(p4.x - p2.x);

    ks.push_back(p2.y - p1.y);
    ks.push_back(p3.y - p1.y);
    ks.push_back(p2.y - p4.y);
    ks.push_back(p3.y - p4.y);

    for (ll k : ks) {
        k = abs(k);
        ll cost = get_cost(
                        point(p1.x, p1.y), 
                        point(p2.x, p2.y - k),
                        point(p3.x - k, p3.y - k),
                        point(p4.x - k, p4.y));
        ans = min(ans, cost);
    }

    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        vector<point> P(4);
        for (point &p : P) {
            cin >> p;
        }

        sort(allof(P));

        ll ans = 1e18;
        do {
            ans = min(ans, solve(P[0], P[1], P[2], P[3]));
        } while (next_permutation(allof(P)));

        cout << ans << "\n";
    }
}
