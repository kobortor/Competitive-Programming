#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef pair<double, double> pt;

const double eps = 1e-6;

struct path {
    pt u, v;
};

pt operator+(pt p1, pt p2) {
    return {p1.first + p2.first, p1.second + p2.second};
}

pt operator-(pt p1, pt p2) {
    return {p1.first - p2.first, p1.second - p2.second};
}

pt operator*(double x, pt p) {
    return {x * p.first, x * p.second};
}

double sq(double x) {
    return x * x;
}

double dist(pt p1, pt p2) {
    return sqrt(sq(p1.first - p2.first) + sq(p1.second - p2.second));
}

ostream& operator<<(ostream &os, pt p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

vector<path>
    paths;

// bool = prof only?
map<pt, vector<pair<pt, bool>>> adj;

map<pt, double> dist_prof, dist_student;

vector<pt> intersect(path p1, path p2, bool debug = false) {
    pt u1 = p1.u;
    pt v1 = p1.v;

    pt u2 = p2.u;
    pt v2 = p2.v;

    pt d1 = v1 - u1;
    pt d2 = v2 - u2;

    if (debug) {
        // cout << endl;
        // cout << "Try " << u1 << "->" << v1 << " and " << u2 << "->" << v2 << endl;
    }

    double det = (d1.first * d2.second - d1.second * d2.first);

    if (abs(det) < 1e-12) {
        if (debug) {
            // cout << d1 << " and " << d2 << endl;
            // cout << "Skip\n";
        }
        return {};
    }

    // matrix
    // [d1x d2x]
    // [d1y d2y]

    // invert
    // [d2y -d2x]
    // [-d1y d1x]
    // ---------
    // d1x * d2y - d1y * d2x
    double a = -(d2.second * (u1 - u2).first - d2.first * (u1 - u2).second) /
               (det);
    double b = (-d1.second * (u1 - u2).first + d1.first * (u1 - u2).second) /
               (det);
    pt joint = u1 + a * d1;

    if (joint.first + eps < min(u1.first, v1.first) ||
        max(u1.first, v1.first) < joint.first - eps) {
        return {};
    }
    if (joint.second + eps < min(u1.second, v1.second) ||
        max(u1.second, v1.second) < joint.second - eps) {
        return {};
    }
    if (joint.first + eps < min(u2.first, v2.first) ||
        max(u2.first, v2.first) < joint.first - eps) {
        return {};
    }
    if (joint.second + eps < min(u2.second, v2.second) ||
        max(u2.second, v2.second) < joint.second - eps) {
        return {};
    }

    return {joint};
}

pt round(pt p) {
    return {round(p.first / eps) * eps, round(p.second / eps) * eps};
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        pt p1{x1, y1};
        pt p2{x2, y2};

        paths.push_back({p1, p2});
    }

    double student_x, student_y, student_speed;
    cin >> student_x >> student_y >> student_speed;

    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    pt p1{x1, y1};
    pt p2{x2, y2};
    paths.push_back({p1, p2});

    double prof_speed;
    cin >> prof_speed;

    pt diff{1.36e-8, 0.97e-8};
    pt ps{student_x, student_y};
    paths.push_back({ps - diff, ps + diff});

    for (int i = 0; i <= n + 1; i++) {
        vector<pt> points;
        points.push_back(paths[i].u);
        points.push_back(paths[i].v);
        for (int j = 0; j <= n + 1; j++) {
            vector<pt> joint = intersect(paths[i], paths[j], i == 2);
            if (!joint.empty()) {
                points.push_back(joint[0]);
            }
        }
        for (int i = 0; i < points.size(); i++) {
            points[i] = round(points[i]);
        }
        sort(points.begin(), points.end());
        points.erase(unique(allof(points)), points.end());
        for (int j = 0; j + 1 < points.size(); j++) {
            adj[points[j]].push_back({points[j + 1], i == n});
            adj[points[j + 1]].push_back({points[j], i == n});
        }

        for (int j = 0; j < points.size(); j++) {
            dist_prof[points[j]] = 1e20;
            dist_student[points[j]] = 1e20;
        }
    }
    // cout << endl;

    priority_queue<pair<double, pt>, vector<pair<double, pt>>,
                   greater<pair<double, pt>>>
        pq_prof, pq_student;
    p1 = round(p1);
    p2 = round(p2);
    ps = round(ps);
    pq_prof.push({0.0, p1});
    dist_prof[p1] = 0.0;
    while (!pq_prof.empty()) {
        auto [d, pos] = pq_prof.top();
        pq_prof.pop();

        // cout << "Prof visit " << pos.first << " " << pos.second << "\n";

        for (auto [nxt_pos, is_prof] : adj[pos]) {
            if (is_prof && dist_prof[nxt_pos] > d + dist(pos, nxt_pos) / prof_speed) {
                dist_prof[nxt_pos] = d + dist(pos, nxt_pos) / prof_speed;
                pq_prof.push({dist_prof[nxt_pos], nxt_pos});
            }
        }
    }

    // cout << endl;

    dist_student[ps] = 0.0;
    pq_student.push({0.0, ps});
    while (!pq_student.empty()) {
        auto [d, pos] = pq_student.top();
        pq_student.pop();

        // cout << "Student visit " << pos.first << " " << pos.second << " at " << d << endl;

        for (auto [nxt_pos, is_prof] : adj[pos]) {
            if (!is_prof && dist_student[nxt_pos] > d + dist(pos, nxt_pos) / student_speed) {
                dist_student[nxt_pos] = d + dist(pos, nxt_pos) / student_speed;
                pq_student.push({dist_student[nxt_pos], nxt_pos});
            }
        }
    }
    
    double ans = 1e20;
    for (auto [pos, dst] : dist_prof) {
        // cout << "Get to " << pos << " at " << dst << " and " << dist_student[pos] << endl;
        if (dist_student[pos] <= dst) {
            ans = min(ans, dst);
        }
    }

    if (ans != 1e20) {
        cout << fixed << setprecision(10) << ans << "\n";
    } else {
        cout << "Impossible\n";
    }
}