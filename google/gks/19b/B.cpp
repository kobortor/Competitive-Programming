#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

struct stone {
    ll s, e, l;
    bool operator<(const stone &ss) const {
        if (s * ss.l == ss.s * l) {
            return e > ss.e;
        } else {
            return s * ss.l < ss.s * l;
        }
    }
};

ll dp[MAXN * MAXN];

void testcase() {
    ll N;
    cin >> N;

    vector<stone> vec;
    while (N--) {
        stone s;
        cin >> s.s >> s.e >> s.l;
        vec.push_back(s);
    }

    sort(allof(vec));

    memset(dp, 0, sizeof dp);
    for (stone ss : vec) {
        for (int a = MAXN * MAXN - 1; a >= ss.s; a--) {
            dp[a] = max(dp[a], dp[a - ss.s] + ss.e - (a - ss.s) * ss.l);
        }
    }

    cout << *max_element(dp, dp + MAXN * MAXN) << "\n";
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;
    for (int a = 1; a <= T; a++) {
        cout << "Case #" << a << ": ";
        testcase();
    }
}
