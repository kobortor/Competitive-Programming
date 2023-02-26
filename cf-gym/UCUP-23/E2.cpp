#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define int ll

bool is_prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

int32_t main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	int ans = 0;

    	for (int g = 1; 2 * g <= n; g++) { //nlogn
			ll tmp = (n - g) / g;
			ll old_ans = ans;
    		for (int i = 1; (i + 1) * g <= n; i++) {
    			ans += tmp / i;
    		}
			cout << g << " " << ans - old_ans << endl;
    	}
    	

    	//for (int i = 1; i < n; i++) ans += numdiv(i) * ((n - 1) / i);
    	/*for (int y = 2; y <= n; y++) { 
    		for (int x = 1; x < y; x++) {
    			int g = __gcd(x, y); 	
    			if ((g - x) % x == 0) ans++;
    		}
    	}*/
    	// printf("%lld\n\n", ans);
		cout << ans << endl;
    }
}
