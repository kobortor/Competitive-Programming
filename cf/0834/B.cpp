#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int mn[26], mx[26];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(mn, 0x3f, sizeof mn);
    memset(mx, -1, sizeof mx);

    int n, k;
    string s;

    cin >> n >> k >> s;

    for (int a = 0; a < n; a++) {
        int id = s[a] - 'A';

        mn[id] = min(mn[id], a);
        mx[id] = max(mx[id], a);
    }

    vector<pii> v;
    for (int a = 0; a < 26; a++) {
        if (mx[a] != -1) {
            v.push_back({mn[a], 1});
            v.push_back({mx[a] + 1, -1});
        }
    }

    sort(allof(v));

    int cnt = 0;
    for (pii p : v) {
        cnt += p.second;
        if (cnt > k) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}
