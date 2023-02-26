#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int POW10[8];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
	POW10[0] = 1;
	for (int i = 1; i < 8; i++) {
		POW10[i] = POW10[i - 1] * 10;
	}

    int t; cin >> t;
    while (t--) {
    	int n; cin >> n;

    	vector<pair<string,string>> curr;
    	for (int i = 0; i < n; i++) {
    		string fir, las;
    		cin >> fir >> las;
    		curr.push_back({fir, las});
    	}

    	pair<int, tuple<int, int, int>> ans;
		ans.first = 1e9;
    	for (int a = 0; a <= 6; a++) {
    		for (int b = 0; b <= 6; b++) {
    			for (int c = 0; c <= 6; c++) {
    				if (a + b + c > 6) continue;
    				if (a + b + c == 0) continue;

    				map<string, int> freq;
    				for (int i = 0; i < n; i++) {
						string s = curr[i].first.substr(0, a) + curr[i].second.substr(0, b);
						freq[s]++;
    				}

					bool good = true;
					for (pair<string, int> p : freq) {
						if (p.second > POW10[c]) {
							good = false;
						}
					}
					if (good) {
						tuple<int, int, int> tmp = {a, b, c};
						ans = min(ans, {a + b + c, tmp});
					}
    			}
    		}
    	}
		cout << get<0>(ans.second) << " " << get<1>(ans.second) << " " << get<2>(ans.second) << "\n";
    }

}
