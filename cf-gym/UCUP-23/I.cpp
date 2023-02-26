#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {

    	int n; cin >> n;
    	int k; cin >> k;

    	vector<int> a(n + 1);
    	for (int i = 1; i <= n; i++)
    		cin >> a[i];

    	vector<int> hi(n + 2);

    	int ans = 0;
    	for (int i = 1; i <= n; i++) {
    		for (int j = i + 1; j <= n; j++) {
    			if (a[j] < a[i]) {
    				hi[i + 1]++;
    				hi[j + 1]--;
    				ans++;
    			}
    		}
    	}

    	vector<int> used(n + 1);

    	while (k--) {

    		vector<int> b(n + 1);
    		for (int i = 1; i <= n; i++) {
    			b[i] = b[i - 1] + hi[i];
    		}

    		int cando = 0;
    		int ind = -1;

    		for (int i = 1; i <= n; i++) {
    			// cout << i << ": " << b[i] << endl;
    			if (b[i] > cando) {
    				ind = i;
    				cando = b[i];
    			}
    		}

    		if (cando == 0) break;

    		int li = ind - 1, ni = ind + 1;
    		while (li > 0 && !used[li + 1]) li--;
    		while (ni <= n && !used[ni]) ni++;

    		// cout << "chose " << li << " " << ind << " " << ni << " " << cando << endl;

    		for (int i = li + 1; i < ind; i++) {
    			for (int j = ind; j < ni; j++) {
    				if (a[j] < a[i]) {
    					// cout << i << " / " << j << endl;
    					ans--;
    					hi[i + 1]--;
    					hi[j + 1]++;
    				}
    			}
    		}

    		used[ind] = 1;

    	}

    	cout << ans << "\n";

    }

}
