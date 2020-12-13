#include<bits/stdc++.h>

// Created by $%U%$ On $%h%$:$%m%$:$%s%$ on $%D%$-$%M%$-$%Y%$

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int n;

int xh, yh, xw, yw;

struct BIT {
    int data[MAXN];
    void update(int pos, int val) {
        pos++;
        while (pos < MAXN) {
            data[pos] = max(data[pos], val);
            pos += pos & -pos;
        }
    }
    int query(int pos) {
        pos++;
        int ans = 0;
        while (pos) {
            ans = max(ans, data[pos]);
            pos -= pos & -pos;
        }

        return ans;
    }
} ds;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    cin >> xh >> yh >> xw >> yw;

    xw -= xh;
    yw -= yh;

    int mx = (xw < 0 ? -1 : +1);
    int my = (yw < 0 ? -1 : +1);

    xw *= mx;
    yw *= my;

    vector<int> ys;
    ys.push_back(0);
    ys.push_back(yw);

    vector<pii> errands;
    for (int i = 0; i < n; i++) {
        int xi, yi;
        cin >> xi >> yi;

        xi -= xh;
        yi -= yh;

        xi *= mx;
        yi *= my;

        if (0 <= xi && xi <= xw && 0 <= yi && yi <= yw) {
            errands.push_back(pii(xi, yi));
            ys.push_back(yi);
        }
    }

    sort(allof(ys));
    yw = lower_bound(allof(ys), yw) - ys.begin();
    for (pii &p : errands) {
        p.second = lower_bound(allof(ys), p.second) - ys.begin();
    }

    sort(allof(errands));

    for (pii &p : errands) {
        ds.update(p.second, ds.query(p.second) + 1);
    }

    cout << *max_element(ds.data, ds.data + MAXN);
}
