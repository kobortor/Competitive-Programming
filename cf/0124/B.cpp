#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vector<int> perm(k);
    vector<string> v(n);

    for (int a = 0; a < k; a++) {
        perm[a] = a;
    }
    for (int a = 0; a < n; a++) {
        cin >> v[a];
    }

    int ans = 2e9 + 9;
    do {
        int mx = -2e9, mn = 2e9;
        for (int a = 0; a < n; a++) {
            string s;
            for (int b = 0; b < k; b++) {
                s += v[a][perm[b]];
            }
            mn = min(mn, stoi(s));
            mx = max(mx, stoi(s));
        }
        ans = min(ans, mx - mn);
    } while (next_permutation(allof(perm)));

    cout << ans;
}
