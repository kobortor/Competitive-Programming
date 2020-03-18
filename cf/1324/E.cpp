#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, h, l, r;
    cin >> n >> h >> l >> r;

    vector<int> cur(h), nxt(h);
    fill(cur.begin() + 1, cur.end(), 0xafafafaf);

    while (n--) {
        int ai;
        cin >> ai;

        fill(allof(nxt), 0xafafafaf);
        for (int i = 0; i < h; i++) {
            int t1 = (i + ai - 1) % h;
            int t2 = (i + ai) % h;
            int g1 = l <= t1 && t1 <= r;
            int g2 = l <= t2 && t2 <= r;

            nxt[t1] = max(nxt[t1], cur[i] + g1);
            nxt[t2] = max(nxt[t2], cur[i] + g2);
        }

        cur = nxt;
    }

    cout << *max_element(allof(cur));
}
