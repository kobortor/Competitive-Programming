#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 55;

int N;
int pos[MAXN];

void fail() {
    cout << "No";
    exit(0);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for (int a = 0; a < 3; a++) {
        int k;
        cin >> k;
        N += k;
        int prv = 99;
        while(k--){
            int x;
            cin >> x;

            if (x > prv) fail(); else prv = x;

            pos[x] = a;
        }
    }

    if (N == 1) {
        if (pos[1] == 0) cout << 1;
        if (pos[1] == 1) cout << "No";
        if (pos[1] == 2) cout << 0;
        return 0;
    }

    ll remain = 0;
    int beg = 0, end = 2;
    while (N >= 2) {
        if (pos[N] == beg) {
            if (pos[N - 1] == beg) {
                remain += 1ll << (N - 1);
                end = 3 - beg - end;
            } else if (pos[N - 1] == end) {
                fail();
            } else {
                remain += 1ll << (N - 1);
                end = 3 - beg - end;
            }
        } else if (pos[N] == end) {
            if (pos[N - 1] == beg) {
                fail();
            } else if (pos[N - 1] == end) {
                beg = 3 - beg - end;
            } else {
                beg = 3 - beg - end;
            }
        } else {
            fail();
        }
        N--;
    }
    if (pos[1] != end) remain++;

    cout << remain;
}
