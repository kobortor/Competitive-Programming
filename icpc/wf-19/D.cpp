#include<bits/stdc++.h>

// Created by $%U%$ On $%h%$:$%m%$:$%s%$ on $%D%$-$%M%$-$%Y%$

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 7;
vector<pii> markers[MAXN];

int circ_delta[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        string str;
        cin >> str;
        int delta = str[0] == 's' ? +1 : -1;
        int idx = stoi(str.substr(1, string::npos));
        markers[idx].push_back({i, delta});
    }

    int base = 0;
    for (int i = 1; i <= 1e6; i++) {
        // if (i == 1) continue;
        int tot = 0;
        int minv = 0;
        for (pii p : markers[i]) {
            tot += p.second;
            minv = min(minv, tot);
        }
        if (tot != 0) continue;

        for (int j = 0; j < markers[i].size(); j++) {
            tot += markers[i][j].second;

            int pos1 = markers[i][j].first;
            int pos2 = markers[i][(j + 1) % markers[i].size()].first;
            
            pos1 = (pos1 + 1) % n;
            pos2 = (pos2 + 1) % n;

            if (tot == minv) {
                if (pos2 <= pos1) {
                    base++;
                }
                // cout << i << " uad from " << pos1 << " to " << pos2 << endl;
                circ_delta[pos1]++;
                circ_delta[pos2]--;
            }
        }
    }

    int best_idx = -1;
    int best = -1;
    int cur = base;
    for (int i = 0; i < n; i++) {
        cur += circ_delta[i];
        // cout << i+1 << " get " << cur << endl;

        if (cur > best) {
            best = cur;
            best_idx = i + 1;
        }
    }
    cout << best_idx << " " << best << endl;
}