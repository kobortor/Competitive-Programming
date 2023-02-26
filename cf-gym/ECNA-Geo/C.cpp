#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

const double PI = atan(1) * 4;

mt19937 g1(chrono::steady_clock::now().time_since_epoch().count());
double randdouble(double a, double b) {return uniform_real_distribution<double>(a, b)(g1);}

typedef long long ll;
typedef pair<double, double> pii
typedef pair<ll, ll> pll;
#define x first
#define y second

vector<pii> v;
int n;
double x, y, r;	

bool cmp(pii p, pii q) {
	return p.x < q.x;
}


double ccw(pii a, pii b, pii c) {
	return (a.y - b.y) * (b.x - c.x) - (a.x - b.x) * (b.y - c.y); //ccw if negative
}

double dist(pii p, pii q) {
	return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
    	cin >> x >> y >> r;
    	r += 10;
    	for (int t = 0; t < 40000; t++) {
    		double ang = randdouble(0, 2 * PI);
    		double nx = x + r * cos(ang);
    		double ny = y + r * sin(ang);
    		v.push_back({nx, ny});
    	}
    }
    sort(v.begin(), v.end());
    vector<pii> up, dn;
    for (pii p : v) {
    	while (up.size() > 1 && ccw(up[up.size() - 2], up.back(), p) < 0) up.pop_back();
    	up.push_back(p);
    	while (dn.size() > 1 && ccw(dn[dn.size() - 2], dn.back(), p) > 0) dn.pop_back();
    	dn.push_back(p);
    }
    double ans = 0;
    for (int i = 1; i < up.size(); i++) {
    	ans += dist(up[i - 1], up[i]);
    }
    for (int i = 1; i < dn.size(); i++) {
    	ans += dist(dn[i - 1], dn[i]);
    }
    printf("%.8f\n", ans);
}
