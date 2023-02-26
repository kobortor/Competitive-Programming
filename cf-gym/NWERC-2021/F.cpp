#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 500;

ll dot(pll p1, pll p2) {
    return p1.first * p2.first + p1.second * p2.second;
}

ll cross(pll p1, pll p2) {
    return p1.first * p2.second - p1.second * p2.first;
}

pll operator-(const pll p1, const pll p2) {
    return {p1.first - p2.first, p1.second - p2.second};
}

ll norm(pll p) {
    return p.first * p.first + p.second * p.second;
}

ll choose2(ll n) {
    return n * (n - 1) / 2;
}

istream& operator>>(istream &is, pll &p) {
    return is >> p.first >> p.second;
}
ostream& operator<<(ostream &os, pll p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
ostream& operator<<(ostream &os, vector<pll> v) {
    for (pll p : v) {
        os << p << " ";
    }
    return os;
}

ll n;
pll start_pt, end_pt;

ll bit[MAXN];

void update_bit(ll x) {
    while (x < MAXN) {
        bit[x]++;
        x += x & -x;
    }
}
ll query_bit(ll x) {
    ll ans = 0;
    while (x) {
        ans += bit[x];
        x -= x & -x;
    }
    return ans;
}

ll helper(vector<pll> v, bool flip) {
    vector<pll> v1 = v;
    vector<pll> v2 = v;

    ll neg = flip ? -1 : +1;

    sort(v1.begin(), v1.end(), [=](pll p1, pll p2) -> bool {
        ll cross_val = neg * cross(p1 - start_pt, p2 - start_pt);
        if (cross_val == 0) {
            return norm(p1 - start_pt) > norm(p2 - start_pt);
        } else {
            return cross_val < 0;
        }
    });

    sort(v2.begin(), v2.end(), [=](pll p1, pll p2) -> bool{
        ll cross_val = neg * cross(p1 - end_pt, p2 - end_pt);
        if (cross_val == 0) {
            return norm(p1 - end_pt) > norm(p2 - end_pt);
        } else {
            return cross_val > 0;
        }
    });

    map<pll, int> index_map;
    for (int i = 0; i < (int)v1.size(); i++) {
        index_map[v1[i]] = i;
    }

    vector<int> perm(v.size());
    for (int i = 0; i < (int)v2.size(); i++) {
        perm[index_map[v2[i]]] = i + 1;
    }

    // counts non-inversions
    ll ans = 0;
    memset(bit, 0, sizeof bit);
    for (int i : perm) {
        ans += query_bit(i);
        update_bit(i);
    }
    return ans;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> start_pt >> end_pt;
    cin >> n;

    vector<pll> north, south, east, west;
    while (n--) {
        pll p;
        cin >> p;

        ll cross_val = cross(p - start_pt, end_pt - start_pt);
        ll dot_val = dot(p - start_pt, end_pt - start_pt);
        if (cross_val == 0) {
            if (dot_val <= 0) {
                east.push_back(p);
            } else {
                west.push_back(p);
            }
        } else if (cross_val < 0) {
            north.push_back(p);
        } else {
            south.push_back(p);
        }
    }

    ll ans = 0;
    ans += choose2(east.size());
    ans += choose2(west.size());
    ans += helper(north, false);
    ans += helper(south, true);
    cout << ans << "\n";
}