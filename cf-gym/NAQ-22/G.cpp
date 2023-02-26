#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 1'000'000'007;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n; cin >> n;

    vector<int> a(n + 1);
    vector<int> vis(n + 1);
    vector<int> wc(n + 1);
    vector<int> onstack(n + 1);

    int cc = 0;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
    	if (vis[i]) continue;

    	int x = i;
    	vector<int> ch;
    	while (1) {
    		if (vis[x]) {
    			int cyclic = onstack[x];
    			for (int y : ch) {
    				// cout << y << " -> ";
    				onstack[y] = 0;
    			}
    			// cout << endl;
    			if (cyclic) {
    				while (1) {
    					int foo = ch.back();
    					ch.pop_back();
    					wc[foo] = cc;
    					// cout << foo << ": " << cc << endl;
    					if (foo == x) break;
    				}
    				cc++;
    				for (int y : ch) {
    					// cout << y << ": " << cc << endl;
    					wc[y] = cc++;
    				}
    			}
    			else {
    				for (int y : ch) {
    					// cout << y << ": " << cc << endl;
    					wc[y] = cc++;
    				}
    			}
    			break;
    		}
    		else {
    			vis[x] = 1;
    			onstack[x] = 1;
    			ch.push_back(x);
    			x = a[x];
    		}
    	}

    }

    vector<vector<int>> g(n + 1);
    vector<int> indeg(n + 1);
    for (int i = 1; i <= n; i++) {
    	// cerr << i << ": " << wc[i] << "\n";
    	int nv = wc[a[i]];
    	int pv = wc[i];
    	if (nv == pv) continue;
    	// cout << nv << " -> " << pv << endl;
    	g[nv].push_back(pv);
    	indeg[pv]++;
    }

    vector<ll> dp(n + 1);

    function<void(int)> dfs = [&](int c) {
    	dp[c] = 1;
    	for (int i : g[c]) {
    		dfs(i);
    		dp[c] *= (dp[i] + 1);
    		dp[c] %= MOD;
    	}
    	// cout << c << ": " << dp[c] << endl;
    };

    ll ans = 1;
    for (int i = 0; i < cc; i++) {
    	if (indeg[i] == 0) {
    		dfs(i);
    		ans *= (dp[i] + 1);
    		ans %= MOD;
    	}
    }

    ans += (MOD - 1);
    ans %= MOD;

    cout << ans << "\n";

}
