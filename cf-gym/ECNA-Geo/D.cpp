#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const double pi = acos(-1);

double square(double x) {
    return x * x;
}

double angle(complex<double> v1, complex<double> v2) {
    return arg(v1 * conj(v2)); // may be negative
}

// third point is the origin
double triangle_area(complex<double> v1, complex<double> v2) {
    double x1 = v1.real();
    double y1 = v1.imag();

    double x2 = v2.real();
    double y2 = v2.imag();
    double ans = (x1 - 0) * (0 + y1) + (x2 - x1) * (y1 + y2) + (0 - x2) * (0 + y2);
    return ans / 2;
}

double solve(vector<complex<double>> points) {
    int n = points.size();
    double answer = 0;
    for (int i = 0; i < n; i++) {
        cout << endl;
        cout << "testing points " << i << " and " << (i + 1) % n << endl;
        complex<double> u = points[i];
        complex<double> v = points[(i + 1) % n];

        cout << "u = " << u << ", v = " << v << endl;

        if ((u * conj(v)).imag() == 0) {
            cout << "Skip\n";
            continue;
        }

        complex<double> u_prime = u / norm(u);
        complex<double> v_prime = v / norm(v);

        cout << "u_prime = " << u_prime << ", v_prime = " << v_prime << endl;

        complex<double> d = v - u;
        complex<double> d_perp{d.imag(), -d.real()};
        double a =
            -1 / norm(d) * (u.real() * d.real() + u.imag() * d.imag());
        complex<double> perp_inter = u + a * d;

        // cout << "Test angle " << angle(perp_inter, u - perp_inter) << endl;
        // cout << "Test angle " << angle(perp_inter, v - perp_inter) << endl;
        complex<double> c = (perp_inter / norm(perp_inter)) / 2.0;
        cout << "c = " << c << endl;
        // cout << "Distance1 = " << norm(c - u_prime) << endl;
        // cout << "Distance2 = " << norm(c - v_prime) << endl;
        // cout << "Distance3 = " << norm(c) << endl;

        double r = sqrt(norm(c));
        cout << "r = "  << r << endl;

        double contrib = 0;
        // contrib += angle(u_prime, v_prime);
        double ext_ang = angle(u_prime - c, v_prime - c);
        if (ext_ang < 0) {
            ext_ang += 2 * pi;
        }
        if (angle(u_prime, v_prime) < 0) {
            ext_ang *= -1;
        }
        contrib += ext_ang * r * r;
        contrib += triangle_area(u_prime, c);
        contrib += triangle_area(c, v_prime);

        cout << "Add " << ext_ang << " * " << r << "^2 = " << ext_ang * r * r << endl;
        cout << "Add " << triangle_area(u_prime, c) << endl;
        cout << "Add " << triangle_area(c, v_prime) << endl;
        cout << "Contrib " << contrib << endl;
        answer += contrib;
    }
    cout << triangle_area({0, 1}, {1, 0}) << endl;
    return abs(answer);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    double x0, y0, r;
    cin >> x0 >> y0 >> r;

    complex<double> origin{x0, y0};

    int n;
    cin >> n;
    vector<complex<double>> points;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        points.push_back((complex<double>{x, y} - origin) / r);
        cout << "Point " << points.back() << endl;
    }

    double ans = solve(points) * r * r;
    cout << ans << " ratio " << ans / 4.112904 << endl;
}
