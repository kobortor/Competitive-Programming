#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<pii> points(8);

int dist(pii p1, pii p2) {
    int dx = p1.first - p2.first;
    int dy = p1.second - p2.second;
    return dx * dx + dy * dy;
}

bool check(vector<int> v) {
    for (int a = 0; a < 4; a++) {
        int i0 = v[a];
        int i1 = v[(a + 4 - 1) % 4];
        int i2 = v[(a + 1) % 4];
        
        int dx1 = points[i1].first - points[i0].first;
        int dy1 = points[i1].second - points[i0].second;

        int dx2 = points[i2].first - points[i0].first;
        int dy2 = points[i2].second - points[i0].second;

        if (dx1 * dx2 + dy1 * dy2 != 0) {
            return false;
        }
    }
    return true;
}

bool check_sq(vector<int> v) {
    int d = dist(points[v[0]], points[v[3]]);
    for (int i = 1; i < 4; i++) {
        if (dist(points[v[i]], points[v[i - 1]]) != d) {
            return false;
        }
    }

    return check(v);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for (pii &p : points) cin >> p.first >> p.second;

    vector<int> indices = {0, 1, 2, 3, 4, 5, 6, 7};
    do {
        vector<int> v1, v2;
        for (int i = 0; i < 4; i++) {
            v1.push_back(indices[i]);
            v2.push_back(indices[i + 4]);
        }

        if (check_sq(v1) && check(v2)) {
            cout << "YES\n";
            for (int i : v1) cout << i + 1 << " ";
            cout << "\n";
            for (int i : v2) cout << i + 1 << " ";
            cout << "\n";
            return 0;
        }
    } while (next_permutation(allof(indices)));
    cout << "NO";
}
