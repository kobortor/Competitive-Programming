#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef pair<double, double> pt;

double W, L;

pt H2, H3;
double R;
pt B1, B2, B3;
double H;

double sqnorm(pt p) {
    return p.first * p.first + p.second * p.second;
}

double norm(pt p) {
    return sqrt(p.first * p.first + p.second * p.second);
}

pt normalize(pt p) {
    double n = norm(p);
    return {p.first / n, p.second / n};
}

pt operator-(pt p1, pt p2) {
    return {p1.first - p2.first, p1.second - p2.second};
}

pt operator+(pt p1, pt p2) {
    return {p1.first + p2.first, p1.second + p2.second};
}

pt operator*(double x, pt p) {
    return {p.first * x, p.second * x};
}

istream &operator>>(istream &is, pt &p) {
    return is >> p.first >> p.second;
}

ostream &operator<<(ostream &os, pt p) {
    return os << "(" << p.first <<", " << p.second << ")";
}

double dot(pt u, pt v) {
    return u.first * v.first + u.second * v.second;
}

double segDist(pt s, pt e, pt p) {
    if (s == e) return norm(p - s);
    auto d = sqnorm(e - s);
    auto t = min(d, max(0., dot(p - s, e - s)));
    return norm(d * (p - s) - t * (e - s)) / d;
}

const double pi = acos(-1);
double angle(pt p) {
    return atan2(p.second, p.first) * 180 / pi;
}

bool check_bad(pt origin, pt collide, pt old) {
    return dot(old - collide, origin - collide) >= 0;
}

pt mirror(pt v, pt across) {
    across = normalize(across);
    pt diff = v - dot(across, v) * across;
    return v - 2 * diff;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> W >> L;
    H2 = {0, L};
    H3 = {W, L};

    cin >> R >> B1 >> B2 >> B3 >> H;

    // Stop being evil!
    // R = R - 1e-9;

    pt C_prime_prime = B2 + 2 * R * normalize(B2 - H2);
    pt B1_prime = B3 + 2 * R * normalize(B3 - H3);
    pt C_prime = B1 + 2 * R * normalize(B1 - B1_prime);
    pt v = mirror(C_prime_prime - C_prime, B1 - C_prime);

    double alpha = (H - C_prime.second) / v.second;
    pt C_star = C_prime + alpha * v;
    double theta = angle(C_prime - C_star);

    if (C_star.first - R < 0 || C_star.first + R > W) {
        cout << "impossible\n";
        return 0;
    }

    if (check_bad(C_star, C_prime, B1)) {
        cout << "impossible\n";
        return 0;
    }
    if (check_bad(B1, B1_prime, B3)) {
        cout << "impossible\n";
        return 0;
    }
    if (check_bad(C_prime, C_prime_prime, B2)) {
        cout << "impossible\n";
        return 0;
    }

    if (segDist(C_star, C_prime, B2) < 2 * R ||
        segDist(C_star, C_prime, B3) < 2 * R) {
        cout << "impossible\n";
        return 0;
    }
    if (segDist(C_prime, C_prime_prime, B3) < 2 * R) {
        cout << "impossible\n";
        return 0;
    }
    if (segDist(B1, B1_prime, B2) < 2 * R) {
        cout << "impossible\n";
        return 0;
    }
    // if (segDist(B2, H2, B1) < 2 * R ||
    //     segDist(B2, H2, B3) < 2 * R) {
    //     cout << "impossible\n";
    //     return 0;
    // }
    // if (segDist(B3, H3, B1) < 2 * R ||
    //     segDist(B3, H3, B2) < 2 * R) {
    //     cout << "impossible\n";
    //     return 0;
    // }

    cout << fixed << setprecision(2) << C_star.first << " " << theta << endl;
}
