#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1010;
int indeg[MAXN];
vector<int> g[MAXN];
int val[MAXN];
vector<int> cs;

void dfs(int c, int d) {

    if (cs.size() >= d) {
        val[cs[cs.size() - d]]++;
    }

    cs.push_back(c);
    
    for (int i : g[c]) {
        dfs(i, d);
    }

    cs.pop_back();

}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int nt = 1;
    int t; cin >> t;
    while (t--) {
    
        int n; cin >> n;
        int d; cin >> d;

        map<string,vector<string>> a;
        vector<string> v;
        for (int i = 0; i < n; i++) {
            
            string s; cin >> s;
            int k; cin >> k;

            vector<string> curr(k);
            for (string &ff : curr) {
                cin >> ff;
                v.push_back(ff);
            }

            v.push_back(s);
            a[s] = curr;

        }

        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());

        n = v.size();

        for (int i = 0; i < n; i++) {
            indeg[i] = 0;
            val[i] = 0;
            g[i].clear();
        }

        auto get = [&](string s) {
            return lower_bound(v.begin(), v.end(), s) - v.begin();
        };

        for (auto [nm, vs] : a) {
            int c = get(nm);
            for (string ss : vs) {
                int i = get(ss);
                g[c].push_back(i);
                indeg[i]++;
            }
        }

        int rt = (min_element(indeg, indeg + n) - indeg);

        dfs(rt, d);

        vector<pair<int,string>> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back({-val[i], v[i]});
        }

        sort(ans.begin(), ans.end());

        while (ans.size() && ans.back().first == 0) ans.pop_back();
        
        if (ans.size() > 3) {
            int lv = ans[2].first;
            while (ans.size() && ans.back().first != lv) ans.pop_back();
        }

        cout << "Tree " << (nt++) << ":\n";
        for (auto [v, nm] : ans) {
            cout << nm << " " << (-v) << "\n";
        }
        cout << "\n";

    }

}
