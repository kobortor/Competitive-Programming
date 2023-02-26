#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

#define ld long double
#define pt pair<ld,ld>
const ld EPS = 1e-8;
const ld PI = 3.141592653589793;

struct Circle

{
	pt center;
	ld expand;
	ld r;

	Circle(pt _c, ld _e, ld _r) {
		center = _c;
		expand = _e;
		r = _r;
	}

	ld x() { return center.first;  }
	ld y() { return center.second; }
	ld areawopi() { return r * r; }
	ld area() { return areawopi() * PI; }

};

ld sq(ld foo) { return foo * foo; }

bool intersect(Circle a, Circle b) {

	ld cdist = sqrtl(sq(a.x() - b.x()) + sq(a.y() - b.y()));
	ld crad = a.r + b.r;

	return (cdist <= crad + EPS);

}

ld req(Circle a, Circle b) {

	ld cdist = sqrt(sq(a.x() - b.x()) + sq(a.y() - b.y()));
	ld crad = a.r + b.r;

	if (cdist <= crad) return 0;
	ld rmt = cdist - crad;

	return (rmt) / (a.expand + b.expand);

}

Circle merge(vector<Circle> curr) {

	ld tx = 0, ty = 0;
	ld tot = 0;

	ld area = 0;
	ld expand = 0;

	for (Circle cc : curr) {
		tx += cc.x();
		ty += cc.y();
		tot++;
		area += cc.areawopi();
		expand = max(expand, cc.expand);
	}

	return Circle({tx / tot, ty / tot}, expand, sqrtl(area));

}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n; cin >> n;

    vector<Circle> rem;
    while (n--) {

    	ld x, y, r, s;
    	cin >> x >> y >> r >> s;
    	rem.push_back(Circle({x, y}, s, r));

    }

    ld currtime = 0;
    while (rem.size() > 1) {

    	n = rem.size();

		set<int> vis;
		vector<int> stk;

    	vector<bool> ch(n);
    	for (int i = 0; i < n; i++) {
    		for (int j = i + 1; j < n; j++) {
    			if (intersect(rem[i], rem[j])) {
					vis.insert(i);
					stk.push_back(i);
					while (!stk.empty()) {
						int top = stk.back();
						stk.pop_back();

						for (int k = 0; k < n; k++) {
							if (!vis.count(k) && intersect(rem[top], rem[k])) {
								vis.insert(k);
								stk.push_back(k);
							}
						}
					}

					for (int k : vis) {
						ch[k] = 1;
					}
					
					i = 9999;
					break;
    			}
    		}
    	}

    	if (count(ch.begin(), ch.end(), true) == 0) {

    		ld rt = 1e40;
    		for (int i = 0; i < n; i++) {
    			for (int j = i + 1; j < n; j++) {
    				rt = min(rt, req(rem[i], rem[j]));
    			}
    		}
    		rt += EPS;

    		// cout << "increment by " << rt << endl;

    		currtime += rt;

    		for (Circle &cc : rem) {
    			cc.r += cc.expand * rt;
    		}

    	}
    	else {

    		vector<int> tt;
    		// cout << fixed << setprecision(5) << "merging: at time " << currtime << endl;;
    		for (int i = 0; i < n; i++) {
    			if (ch[i]) {
    				tt.push_back(i);
    				// cout << fixed << setprecision(5) << rem[i].x() << " " << rem[i].y() << " " << rem[i].r << endl;
    			}
    		}

    		reverse(tt.begin(), tt.end());
    		vector<Circle> have;

    		for (int x : tt) {
    			have.push_back(rem[x]);
    			rem.erase(rem.begin() + x);
    		}

    		rem.push_back(merge(have));

    	}

    }

    cout << fixed << setprecision(12) << rem[0].x() << " " << rem[0].y() << "\n" << rem[0].r << "\n";

}
