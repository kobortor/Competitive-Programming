#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
#define ld long double
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {

    	ll n; ld v;
    	cin >> n >> v;

    	vector<pair<ld,ld>> neg, pos;
    	while (n--) {

    		ll x, cv;
    		cin >> x >> cv;

    		if (x < 0) neg.push_back({x, cv});
    		else pos.push_back({x, cv});

    	}

    	ld lo = 0, hi = 4e12;
    	for (int it = 0; it < 500; it++) {

    		ld tl = -1e18, tr = 1e18;
    		ld avg = (lo + hi) / 2;

    		for (auto [x, speed] : neg) {
    			tl = max(tl, x + speed * avg);
    		}
    		for (auto [x, speed] : pos) {
    			tr = min(tr, x - speed * avg);
    		}

    		if (tl < tr) lo = avg;
    		else hi = avg;

    	}

    	ld ans = v * lo;

    	cout << fixed << setprecision(15) << ans << "\n";

    }

}
