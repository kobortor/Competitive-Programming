#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

template <class T> int sgn(T x) {return (x > 0) - (x < 0);}
template <class T> 
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const {return tie(x,y) < tie(p.x, p.y);}
	bool operator==(P p) const {return tie(x,y) == tie(p.x, p.y);}
	P operator+(P p) const {return P(x+p.x, y+p.y);}
	P operator-(P p) const {return P(x-p.y, y-p.y);}
	P operator*(T d) const {return P(x*d, y*d);}
	P operator/(T d) const {return P(x/d, y/d);}
	T dot(P p) const {return x*p.x + y*p.y;}
	T cross(P p) const {return x*p.y - y*p.x;}
	T cross(P a, P b) const {return (a-*this).cross(b-*this);}
	T dist2() const {return x*x + y*y;}
	double dist() const {return sqrt((double) dist2());}
	double angle() const {return atan2(y,x);}
};

template<class P> bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

template<class P> vector<P> segInter(P a, P b, P c, P d) {
	auto oa = c.cross(d, a), ob = c.cross(d, b),
	     oc = a.cross(b, c), od = a.cross(b, d);
	if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
		return {(a * ob - b * oa) / (ob - oa)};
	set<P> s;
	if (onSegment(c, d, a)) s.insert(a);
	if (onSegment(c, d, b)) s.insert(b);
	if (onSegment(a, b, c)) s.insert(c);
	if (onSegment(a, b, d)) s.insert(d);
	return {all(s)};
}

template<class P>
bool inPolygon(vector<P> &p, P a, bool strict = true) {
	int cnt = 0, n = sz(p);
	rep(i,0,n) {
		P q = p[(i+1)%n];
		cnt ^= ((a.y<p[i].y) - (a.y<q.y)) * a.cross(p[i], q) > 0;
	}
	return cnt;
}

typedef Point<double> P;

const int MN = 4000005;

int n, m, x, y, id, which[MN], col, vis[MN], st;
double mn;
P loc[MN];
vector<int> adj[MN];
vector<pair<int, int>> segs;
vector<P> polys[205];

bool sample(P tmp) {
	bool out = true;
	for (int i = 1; i <= n; i++) out &= !inPolygon(polys[i], tmp);
	return out;
}

bool outside(int i, int j) {
	bool ok1 = true, ok2 = true;
	P tmp1 = P((loc[i].x + loc[j].x) / 2.0 + 0.00069, (loc[i].y + loc[j].x) / 2.0 + 0.000123);
	P tmp2 = P((loc[i].x + loc[j].x) / 2.0 - 0.00069, (loc[i].y + loc[j].x) / 2.0 - 0.000123);
	if (sample(tmp1) && !sample(tmp2)) return true;
	if (!sample(tmp1) && sample(tmp2)) return true;
	return false;
}

void add(int i, int j) {
	adj[i].push_back(j);
	adj[j].push_back(i);
}

void dfs(int cur) {
	vis[cur] = 1;
	if (loc[cur].x < mn) mn = loc[cur].x, st = cur;
	for (int nxt : adj[cur]) if (!vis[nxt]) dfs(nxt);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
    	cin >> m;
    	col++;
    	vector<int> v;
    	for (int j = 0; j < m; j++) {
    		cin >> x >> y;
    		loc[++id] = P(x, y);
    		polys[i].push_back(loc[id]);
    		which[id] = col;
    		v.push_back(id);
    	}
    	for (int j = 0; j < m; j++) {
    		adj[v[j]].push_back(v[(j+1)%m]);
    		adj[v[(j+1)%m]].push_back(v[j]);
    		segs.push_back({j, (j+1)%m});
    	}
    }
    int orig = id;
    for (int i = 0; i < segs.size(); i++) {
    	for (int j = i + 1; j < segs.size(); j++) {
    		if (which[segs[i].f] == which[segs[j].f]) continue;
    		vector<P> nw = segInter(loc[segs[i].f], loc[segs[i].s], loc[segs[j].f], loc[segs[j].s]);
    		assert(nw.size() <= 1);
    		if (nw.empty()) continue;
    		loc[++id] = nw[0];
    		add(segs[i].f, id);
    		add(segs[i].s, id);
    		add(segs[j].f, id);
    		add(segs[j].s, id);
    	}
    }
    double ans = 0;
    for (int i = 1; i <= id; i++) {
    	if (vis[i]) continue;
    	mn = 1e18;
    	dfs(i);
    	printf("Starting at (%.2f, %.2f)\n", loc[st].x, loc[st].y);
    	vector<int> ord;
    	int cur = st, pre = 0;
    	while (true) {
    		for (int nxt : adj[cur]) {
    			if (nxt == pre) continue;
    			if (outside(cur, nxt)) {
    				ord.push_back(nxt);
    				pre = cur;
    				cur = nxt;
    				break;
    			}
    		}
    		printf("%d\n", cur);
    		if (cur == st) break;
    	}
    	for (int i = 0; i < ord.size(); i++) {
    		ans += loc[ord[i]].x * loc[ord[(i+1)%ord.size()]].y - loc[ord[i]].y * loc[ord[(i+1)%ord.size()]].x;
    	}
    }
    printf("%.8f\n", ans);
}
