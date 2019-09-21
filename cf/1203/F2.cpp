#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

//dp[i] is the best result with `i` taken
int dp[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, r;
    cin >> n >> r;

    //put 0s in positives
    vector<pii> positive;
    vector<pair<int, pii>> negative;
    while (n--) {
        int a, b;
        cin >> a >> b;
        a = max(a, -b);

        if (b >= 0) {
            positive.push_back({a, b});
        } else {
            negative.push_back({a + b, {a, b}});
        }
    }

    int doable = 0;

    sort(allof(positive));
    for (pii p : positive) {
        if (r >= p.first) {
            doable++;
            r += p.second;
        } else {
            break;
        }
    }

    memset(dp, 0xaf, sizeof dp);
    dp[0] = r;

    sort(allof(negative));
    reverse(allof(negative));
    for (int a = 0; a < (int)negative.size(); a++) {
        for (int b = a + 1; b >= 1; b--) {
            if (dp[b - 1] >= negative[a].second.first) {
                dp[b] = max(dp[b], dp[b - 1] + negative[a].second.second);
            }
        }
    }

    int max_cnt = 0;
    for (int a = 0; a < MAXN; a++) {
        if (dp[a] >= 0) {
            max_cnt = a;
        }
    }

    cout << doable + max_cnt;
}
