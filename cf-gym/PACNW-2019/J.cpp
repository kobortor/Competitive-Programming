#include <bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef pair<double, double> pdd;

const double pi = acos(-1);
const double tau = 2 * pi;

struct diff {
    double dslope = 0, dcons = 0;
    void operator+=(const diff d) {
        dslope += d.dslope;
        dcons += d.dcons;
    }
    bool operator<(const diff d) const {
        return false;
    }
};

ostream& operator<<(ostream &os, diff &d) {
    return os << "(" << d.dslope << ", " << d.dcons << ")";
}

map<double, diff> points;

void add_arc(double l, double r, double slope, double start_cons) {
    l = fmod(l, tau);
    r = fmod(r, tau);
    if (l < 0) l += tau;
    if (r < 0) r += tau;

    if (l <= r) { // ok
        points[l] += diff{slope, start_cons - l * slope};
        points[r] += diff{-slope, -(start_cons - l * slope)};
    } else {
        add_arc(l, tau - 1e-9, slope, start_cons);
        add_arc(0, r, slope, (tau - l) * slope + start_cons);
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;
    while (N--) {
        double T, s, a;
        cin >> T >> s >> a;
        if (T > s * pi) { // warps around
            double opp = fmod(a + pi, tau);

            add_arc(opp, a, s, T - s * pi);
            add_arc(a, opp, -s, T);
        } else {
            double l = a - T / s;
            double r = a + T / s;

            add_arc(l, a, s, 0);
            add_arc(a, r, -s, T);
        }
    }

    double ans = 0;
    double cons = 0;
    double slope = 0;
    for (auto [x, d] : points) {
        ans = max(ans, x * slope + cons);
        slope += d.dslope;
        cons += d.dcons;
    }
    cout << fixed << setprecision(6) << ans << endl;
}