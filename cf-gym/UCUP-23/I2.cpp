#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MN = 6005;

int n, k, t, a[MN], dp[MN][MN], invs[MN][MN];

void rec(int lvl, int l, int r, int p1, int p2) {
	int mid = (l + r) / 2, opt = 0;
	for (int i = p1; i <= min(mid, p2); i++) {
		if (dp[mid][lvl] > dp[i - 1][lvl - 1] + invs[i][mid]) {
			dp[mid][lvl] = dp[i - 1][lvl - 1] + invs[i][mid];
			opt = i;
		}
	}
	if (l == r) return;
	rec(lvl, l, mid, p1, opt), rec(lvl, mid + 1, r, opt, p2);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> t;
    while (t--) {
    	cin >> n >> k;
    	k++;
    	for (int i = 1; i <= n; i++) cin >> a[i];
    	for (int i = 1; i <= n; i++) {
    		for (int j = i + 1; j <= n; j++) {
    			//compute invs
    			if (a[j] < a[i]) {
    				invs[i][j]++;
    			}
    		}
    	}

    	for (int i = n; i > 0; i--) {
    		for (int j = 1; j <= n; j++) {
    			invs[i][j] += invs[i][j - 1];
    		}
    		if (i < n) {
    			for (int j = n; j > 0; j--) {
    				invs[i][j] += invs[i + 1][j];
    			}
    		}
    	}

    	for (int i = 1; i <= n; i++) dp[i][1] = invs[1][i];
    		int ans = dp[n][1];
    	for (int j = 2; j <= k; j++) {
    		for (int i = 1; i <= n; i++) dp[i][j] = 0x3f3f3f3f;
    		rec(j, 1, n, 1, n);
    		ans = min(ans, dp[n][j]);
    	}
    	printf("%d\n", ans);
    	for (int i = 1; i <= n; i++) {
    		for (int j = i; j <= n; j++) {
    			invs[i][j] = 0;
    		}
    	}
    }
}
