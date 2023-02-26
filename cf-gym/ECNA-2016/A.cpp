#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 22;

struct circle {
    double x, y, z, r, v;
};

vector<circle> circles;

// [idx] -> [(next, fraction of circle)]
vector<pair<int, double>> adj[MAXN];

const double pi = acos(-1);
double flow[MAXN];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        circle c;
        cin >> c.x >> c.y >> c.z >> c.r >> c.v;
        circles.push_back(c);
    }
    sort(circles.begin(), circles.end(),
         [](circle c1, circle c2) { return c1.z > c2.z; });

    for (int i = 0; i < n; i++) { // find which circles the cup `i` will flow into
        // (pos, idx, +/1)
        vector<tuple<double, int, int>> points;
        for (int j = 0; j < n; j++) {
            if (i == j || circles[i].z <= circles[j].z) {
                continue;
            }
            double mid =
                atan2(circles[j].x - circles[i].x, circles[j].y - circles[i].y);
            // angle of intersection

            double a = circles[i].r;
            double b = hypot(circles[i].x - circles[j].x, circles[i].y - circles[j].y);
            double c = circles[j].r;
            double det = (a * a + b * b - c * c) / (2 * a * b);

            if (a >= b + c) { // circles[j] is completely under
                continue;
            }
            if (det > +1) { // circle[i] completely falls into circle[j]
                continue;
            }

            if (det < -1) { // all of circle[i] is covered
                det = -1;
            }
            double angle = acos(det);
            for (int k = -1; k <= 1; k++) {
                points.push_back({mid - angle + 2 * k * pi, j, -1});
                points.push_back({mid + angle + 2 * k * pi, j, +1});
            }
        }

        sort(points.begin(), points.end());
        vector<pii> kept;
        double prev_x = -100;
        for (auto [x, j, t] : points) {
            double l = max(prev_x, -pi);
            double r = min(x, pi);
            if (l < r && !kept.empty()) {
                int id = max_element(kept.begin(), kept.end())->second;
                adj[i].push_back({id, (r - l) / (2 * pi)});
            }

            if (t == -1) {
                kept.push_back({circles[j].z, j});
            } else {
                kept.erase(find(kept.begin(), kept.end(), pii(circles[j].z, j)));
            }

            prev_x = x;
        }
    }

    double total_time = 0;
    while (any_of(circles.begin(), circles.end(),
                  [](circle c) { return c.v > 1e-9; })) {
        fill(flow, flow + n, 0.0);
        flow[0] = 100;
        for (int i = 0; i < n; i++) {
            if (circles[i].v < 1e-9) {
                for (auto [j, rate] : adj[i]) {
                    flow[j] += rate * flow[i];
                }
            }
        }

        double tm = 1e15;
        for (int i = 0; i < n; i++) {
            if (circles[i].v > 1e-9 && flow[i] > 1e-9) {
                tm = min(tm, circles[i].v / flow[i]);
            }
        }
        if (tm == 1e15) {
            cout << "Invalid\n";
            return 0;
        }

        total_time += tm;
        for (int i = 0; i < n; i++) {
            circles[i].v = max(0.0, circles[i].v - flow[i] * tm);
        }
    }

    cout << fixed << setprecision(2) << total_time << endl;
}