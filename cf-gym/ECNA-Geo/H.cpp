#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define ld long double
#define pt complex<ld>
const ld PI = 3.141592653589;

ld dot(pt x, pt y) {
	return (x.real() * y.real() + x.imag() * y.imag());
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ld w, l; cin >> w >> l;

    ld r;
    pt p1, p2, p3;
    ld h;

    cin >> r;
    {
    	ld x, y; cin >> x >> y;
    	p1 = complex<ld>(x, y);
    }
    {
    	ld x, y; cin >> x >> y;
    	p2 = complex<ld>(x, y);
    }
    {
    	ld x, y; cin >> x >> y;
    	p3 = complex<ld>(x, y);
    }
    cin >> h;

    pt tl(0, l);
    pt tr(w, l);

    pt d3 = tr - p3;
    pt g3 = p3 - d3 * (2 * r / abs(d3));
    pt d1 = g3 - p1;
    pt g1 = p1 - d1 * (2 * r / abs(d1));
    pt d2 = tl - p2;
    pt g2 = p2 - d2 * (2 * r / abs(d2));
    pt vr = g2 - g1;
    pt _norm = vr - ((dot(vr, d1)) / (abs(d1) * abs(d1))) * d1;
    pt res = vr - ((ld)2) * _norm;
    pt ans = g1 - res * ((g1.imag() - h) / res.imag());

    ld nx = ans.real();

    ld cmin = min({
    	dot(vr, d2),
    	dot(d1, d3),
    	dot(-res, d1)
    });

    if (nx < 0 || nx > w || cmin < 0) {
    	cout << "impossible\n";
    	return 0;
    }

    ld COS = -(res.real()) / abs(res);

    ld ang = acosl(COS) * 180.0 / PI;

    cout << fixed << setprecision(2) << nx << " " << ang << "\n";

}
