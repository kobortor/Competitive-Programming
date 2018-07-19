#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2001;

int N;

int dpx0[MAXN];
int dpx1[MAXN];
int dpy0[MAXN];
int dpy1[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(dpx0, 0x3f, sizeof dpx0);
    memset(dpx1, 0x3f, sizeof dpx1);
    memset(dpy0, 0x3f, sizeof dpy0);
    memset(dpy1, 0x3f, sizeof dpy1);

    cin >> N;

    pii prv = pii(1000, 1000);
    dpx0[1000] = 0;
    dpy0[1000] = 0;

    for(int a = 1; a <= N; a++){
        int x, y;
        cin >> x >> y;
        x += 1000;
        y += 1000;

        for(int b = 0; b < MAXN; b++){
            dpx1[b] = min(dpx1[b], dpx0[b] + abs(prv.second - y));
            dpy1[prv.second] = min(dpy1[prv.second], dpx0[b] + abs(b - x));

            dpx1[prv.first] = min(dpx1[prv.first], dpy0[b] + abs(b - y));
            dpy1[b] = min(dpy1[b], dpy0[b] + abs(prv.first - x));
        }

        prv = pii(x, y);

        memcpy(dpx0, dpx1, sizeof dpx1);
        memcpy(dpy0, dpy1, sizeof dpy1);

        memset(dpx1, 0x3f, sizeof dpx1);
        memset(dpy1, 0x3f, sizeof dpy1);
    }

    cout << min(*min_element(dpx0, dpx0 + MAXN), *min_element(dpy0, dpy0 + MAXN));
}
