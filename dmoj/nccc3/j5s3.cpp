/*
This is a slightly modified submission from a very old CCC junior problem
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

template<class T>
using minheap = priority_queue<T, vector<T>, greater<T>>;

#define allof(x) x.begin(), x.end()

const int MAXN = 105 * 105;

struct point {
    double x, y;
    point (double _x, double _y){
        x = _x;
        y = _y;
    }
    point operator+(const point &p) const {
        return {x + p.x, y + p.y};
    }
    point operator-(const point &p) const {
        return {x - p.x, y - p.y};
    }
    point operator*(double d) const {
        return {x * d, y * d};
    }
    point rot90() const {
        return {y, -x};
    }

    double distance_to(const point &p) const {
        return hypot(x - p.x, y - p.y);
    }
};

struct line {
    double mx, b;
    bool vertical;
    line (double _mx, double _b){
        mx = _mx;
        b = _b;
        vertical = false;
    }

    line (const point &pa, const point &pb){
        if(pa.x == pb.x){
            vertical = true;
            mx = pa.x;
        } else {
            vertical = false;
            mx = (pb.y - pa.y) / (pb.x - pa.x);

            /*
            y - pa.y = mx (x - pa.x)
            y = mx * x + pa.y - mx * pa.x
            b = pa.y - mx * pa.x
            */
            b = pa.y - mx * pa.x;
        }
    }
    point intersect(const line &ln) const {
        if(vertical){
            return ln.intersect(*this);
        }
        if(ln.vertical){
            return {ln.mx, mx * ln.mx + ln.b};
        } else {
            double mx1 = mx - ln.mx;
            double b1 = ln.b - b;

            double xint = b1 / mx1;
            return {xint, mx * xint + b};
        }
    }

    bool parallel(const line &ln) const {
        if(vertical && ln.vertical) {
            return true;
        }
        if(vertical || ln.vertical) {
            return false;
        }
        return mx == ln.mx;
    }
};
line perp_bisect(const point &pa, const point &pb) {
    point mid = (pa + pb) * 0.5;

    point tmpa = (pa - mid).rot90() + mid;
    point tmpb = (pb - mid).rot90() + mid;

    // printf("(%f, %f) and (%f, %f)\n", tmpa.x, tmpa.y, tmpb.x, tmpb.y);

    return line(tmpa, tmpb);
}

int N;
vector<point> points;

int main(){
    // cin.tie(0);
    // cin.sync_with_stdio(0);

    cin >> N;

    if(N == 1){
        cout << 0;
        return 0;
    }

    for(int a = 0; a < N; a++){
        point p(0,0);
        cin >> p.x >> p.y;

        bool good = true;
        for(point pp : points){
            if(pp.x == p.x && pp.y == p.y){
                good = false;
            }
        }
        if(good){
            points.push_back(p);
        }
    }
    N = points.size();

    double best = 1e19;
    for(int a = 0; a < N; a++){
        for(int b = a + 1; b < N; b++){
            //testing this
            point mid = (points[a] + points[b]) * 0.5;
            double tt = 0;
            for(int d = 0; d < N; d++){
                tt = max(tt, mid.distance_to(points[d]));
            }
            best = min(best, tt);

            for(int c = b + 1; c < N; c++){
                line ab = perp_bisect(points[a], points[b]);
                line bc = perp_bisect(points[b], points[c]);

                // printf("Find %f x + %f\n", ab.mx, ab.b);
                // printf("Find %f x + %f\n", bc.mx, bc.b);

                if(ab.parallel(bc)){
                    // printf("parallel\n");
                    continue;
                } else {
                    double tmp = 0;
                    // printf("not parallel\n");
                    point p = ab.intersect(bc);

                    // printf("Found at %f %f\n", p.x, p.y);

                    for(int d = 0; d < N; d++){
                        tmp = max(tmp, p.distance_to(points[d]));
                    }
                    best = min(best, tmp);
                }
            }
        }
    }
    cout << fixed << setprecision(15) << best << "\n";
}
