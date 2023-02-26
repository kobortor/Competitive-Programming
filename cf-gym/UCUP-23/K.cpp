#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define f first
#define s second

const int MN = 10;

int t, n, k;
char a[MN][MN];

bool winning() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - k + 1; j++) {
			if (a[i][j] == '.') continue;
			bool ok = 1;
			for (int l = 0; l < k; l++) ok &= a[i][j + l] == a[i][j];
			if (ok) return true;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - k + 1; j++) {
			if (a[j][i] == '.') continue;
			bool ok = 1;
			for (int l = 0; l < k; l++) ok &= a[j + l][i] == a[j][i];
			if (ok) return true;
		}
	}
	for (int i = 1; i <= n - k + 1; i++) {
		for (int j = 1; j <= n - k + 1; j++) {
			if (a[i][j] == '.') continue;
			bool ok = 1;
			for (int l = 0; l < k; l++) ok &= a[i + l][j + l] == a[i][j];
			if (ok) return true;
		}
	}
	for (int i = k; i <= n; i++) {
		for (int j = 1; j <= n - k + 1; j++) {
			if (a[i][j] == '.') continue;
			bool ok = 1;
			for (int l = 0; l < k; l++) ok &= a[i - l][j + l] == a[i][j];
			if (ok) return true;
		}
	}
	return false;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> t;
    outer: while (t--) {
    	vector<pii> out, vx, vo;
    	cin >> n >> k;
    	int cx = 0, co = 0;
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= n; j++) {
    			cin >> a[i][j];
    			if (a[i][j] == 'x') cx++;
    			if (a[i][j] == 'o') co++;
    		}
    	}
    	if (abs(cx - co) > 1) {printf("NIE\n"); goto outer;}
    	if (winning()) {
    		int li = 0, lj = 0;
    		for (int i = 1; i <= n; i++) {
    			for (int j = 1; j <= n; j++) {
    				if (a[i][j] == '.') continue;
    				char old = a[i][j];
    				a[i][j] = '.';
    				if (!winning()) li = i, lj = j;
    				a[i][j] = old;
    			}
    		}
    		if (!li) {printf("NIE\n"); goto outer;}
    		for (int i = 1; i <= n; i++) {
    			for (int j = 1; j <= n; j++) {
    				if (i == li && j == lj) continue;
    				if (a[i][j] == 'x') vx.push_back({i, j});
    				if (a[i][j] == 'o') vo.push_back({i, j});
    			}
    		}
    		if (a[li][lj] == 'x') {
    			if (cx == co + 1) {
    				for (int i = 0; i < co; i++) out.push_back(vx[i]), out.push_back(vo[i]);
    				out.push_back({li, lj});
    			} else if (cx == co) {
    				for (int i = 0; i < cx - 1; i++) out.push_back(vo[i]), out.push_back(vx[i]);
    				out.push_back(vo[cx - 1]);
    				out.push_back({li, lj});
    			} else {printf("NIE\n"); goto outer;}
    		} else {
    			if (co == cx + 1) {
    				for (int i = 0; i < cx; i++) out.push_back(vo[i]), out.push_back(vx[i]);
    				out.push_back({li, lj});
    			} else if (cx == co) {
    				for (int i = 0; i < co - 1; i++) out.push_back(vx[i]), out.push_back(vo[i]);
    				out.push_back(vx[co - 1]);
    				out.push_back({li, lj});
    			} else {printf("NIE\n"); goto outer;}
    		}
    		printf("TAK\n");
    		for (pii p : out) printf("%d %d\n", p.f, p.s);
    	} else {
    		if (co + cx < n * n) {printf("NIE\n"); goto outer;}
    		for (int i = 1; i <= n; i++) {
    			for (int j = 1; j <= n; j++) {
    				if (a[i][j] == 'x') vx.push_back({i, j});
    				if (a[i][j] == 'o') vo.push_back({i, j});
    			}
    		}
    		if (co == cx + 1) {
    			for (int i = 0; i < cx; i++) out.push_back(vo[i]), out.push_back(vx[i]);
    			out.push_back(vo.back());
    		} else if (cx == co + 1) {
    			for (int i = 0; i < co; i++) out.push_back(vx[i]), out.push_back(vo[i]);
    			out.push_back(vx.back());
    		} else if (co == cx) {
				for (int i = 0; i < cx; i++) out.push_back(vo[i]), out.push_back(vx[i]);
    		} else {
    			printf("NIE\n"); goto outer;
    		}
    		printf("TAK\n");
    		for (pii p : out) printf("%d %d\n", p.f, p.s);
    	}
    }
}
