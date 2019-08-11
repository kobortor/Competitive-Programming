#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, h, m;
    cin >> n >> h >> m;

    vector<int> ht(n, h);
    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;

        for (int a = l - 1; a < r; a++) {
            ht[a] = min(ht[a], x);
        }
    }

    int ans = 0;
    for (int a = 0; a < n; a++) {
        ans += ht[a] * ht[a];
    }
    
    cout << ans;
}
