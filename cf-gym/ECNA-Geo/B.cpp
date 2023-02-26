#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 22;
const double pi = acos(-1);

double square(double x) {
    return x * x;
}

struct Circle {
    double x, y, z, r, v;

    bool operator<(const Circle &c) const {
        return z > c.z;
    }
};

double dist(Circle c1, Circle c2) {
    return sqrt(square(c1.x - c2.x) + square(c1.y - c2.y));
}

vector<Circle> circles;

double flow[MAXN];
vector<pair<int, double>> adj[MAXN];

int n;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        Circle c;
        cin >> c.x >> c.y >> c.z >> c.r >> c.v;
        circles.push_back(c);
    }

    sort(allof(circles));

    for (int i = 0; i < n; i++) {
        vector<tuple<double, int, int>> points;
        for (int j = i + 1; j < n; j++) {
            if (circles[i].z > circles[j].z &&
                dist(circles[i], circles[j]) <= circles[i].r + circles[j].r && // not disjoint
                dist(circles[i], circles[j]) + circles[j].r > circles[i].r) {  // not completely inside
                double a = circles[i].r;
                double b = dist(circles[i], circles[j]);
                double c = circles[j].r;
                double cos_theta = -(c * c - a * a - b * b) / (2 * a * b);
                if (cos_theta < -1) {
                    cos_theta = -1;
                }
                double theta = acos(cos_theta);
                double ang = atan2(circles[j].x - circles[i].x,
                                   circles[j].y - circles[i].y);

                for (int k = -1; k <= 1; k++) {
                    points.push_back({ang - theta + k * 2 * pi, j, -1});
                    points.push_back({ang + theta + k * 2 * pi, j, +1});
                }
            }
        }
        sort(allof(points));

        vector<int> current;

        double prev_x = -999;
        for (auto [x, idx, tp] : points) {
            // cout << "Get " << x << " " << idx << " " << tp << endl;

            double l = max(prev_x, -pi);
            double r = min(x, +pi);
            if (l < r && !current.empty()) {
                int j = *min_element(allof(current));
                // cout << i << " -> " << j << " by " << (r - l) / (2 * pi) << endl;
                adj[i].push_back({j, (r - l) / (2 * pi)});
            }

            if (tp == -1) {
                current.push_back(idx);
            } else {
                auto iter = find(allof(current), idx);
                current.erase(iter);
            }

            prev_x = x;
        }
    }

    double total_time = 0;
    while (any_of(allof(circles), [](Circle c) { return c.v > 1e-9; })) {
        fill(flow, flow + n, 0);
        flow[0] = 100;

        for (int i = 0; i < n; i++) {
            if (circles[i].v < 1e-9) {
                for (auto [j, amnt] : adj[i]) {
                    flow[j] += amnt * flow[i];
                }
            }

            // cout << "Flow of " << i << " is " << flow[i] << endl;
        }

        double tm = 1e15;
        for (int i = 0; i < n; i++) {
            if (circles[i].v > 1e-9 && flow[i] > 0) {
                tm = min(tm, circles[i].v / flow[i]);
            }
        }

        if (tm == 1e15) {
            cout << "Invalid\n";
            return 0;
        }

        for (int i = 0; i < n; i++) {
            circles[i].v -= flow[i] * tm;
        }
        // cout << "Move forward " << tm << endl;
        total_time += tm;
    }
    cout << fixed << setprecision(2) << total_time << endl;
}
