#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

const int INF = 1e10;

ll tm_nxt[MAXN];

ll solve(ll N, ll l1, ll l2, vector<ll> v1, vector<ll> v2) {
    for (int i = 0; i < l2; i++) {
        if (v2[(i + l1) % l2]) {
            tm_nxt[i] = 1;
        } else {
            tm_nxt[i] = INF;
        }
    }
    for (int i = 0; i < l2; i++) {
        if (tm_nxt[i] == 1) {
            int j = i;
            while (tm_nxt[((j - l1) % l2 + l2) % l2] > tm_nxt[j] + 1) {
                int prvj = ((j - l1) % l2 + l2) % l2;
                tm_nxt[prvj] = tm_nxt[j] + 1;
                j = prvj;
            }
        }
    }

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for (int i = 0; i < l1; i++) {
        if (v1[i]) {
            if (v2[i % l2]) {
                pq.push({i, i});
            } else if (tm_nxt[i % l2] != INF) {
                pq.push({i + l1 * tm_nxt[i % l2], i});
            }
        }
    }

/*
    cout << "tm_nxt\n";
    for (int i = 0; i < l2; i++) {
        cout << tm_nxt[i] << " ";
    }
    cout << endl;
    */

    ll tm;
    while (N--) {
        if (pq.empty()) return -1;

        pll top = pq.top();
        pq.pop();

        tm = top.first;
        //cout << "Foudn time " << tm << endl;

        ll l1_pos = tm % l1;
        ll l2_pos = tm % l2;

        if (tm_nxt[l2_pos] != INF) {
            pq.push({tm + tm_nxt[l2_pos] * l1, l1_pos});
        }
    }
    return tm + 1;
}

int32_t main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll N;
    cin >> N;
    string S1, S2, S3, S4;
    cin >> S1 >> S2 >> S3 >> S4;

    vector<ll> v1(S1.size() * S2.size()), v2(S3.size() * S4.size());
    for (int i = 0; i < S1.size() * S2.size(); i++) {
        if (S1[i % S1.size()] == 'T' && S2[i % S2.size()] == 'T') {
            v1[i] = 1;
        }
    }
    for (int i = 0; i < S3.size() * S4.size(); i++) {
        if (S3[i % S3.size()] == 'P' && S4[i % S4.size()] == 'C') {
            v2[i] = 1;
        }
    }

    cout << solve(N, S1.size() * S2.size(), S3.size() * S4.size(), v1, v2);
}
