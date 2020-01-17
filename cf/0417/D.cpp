#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct Friend {
    ll cost;
    ll min_monitor;

    // represented as a bitset
    ll problems;

    bool operator< (const Friend &f) const {
        return min_monitor < f.min_monitor;
    }
};

ll dp[1 << 20];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m, b;
    cin >> n >> m >> b;

    vector<Friend> friends;
    while (n--) {
        ll xi, ki, mi;
        cin >> xi >> ki >> mi;

        ll problems = 0;
        while (mi--) {
            ll p;
            cin >> p;
            problems |= (1 << (p - 1));
        }

        friends.push_back(Friend{xi, ki, problems});
    }

    sort(allof(friends));
    reverse(allof(friends));

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;

    for (Friend f : friends) {
        dp[f.problems] = min(dp[f.problems], f.min_monitor * b + f.cost);
        for (int state = 1; state < (1 << m); state++) {
            dp[state | f.problems] = min(dp[state | f.problems], dp[state] + f.cost);
        }
    }

    int final_state = (1 << m) - 1;
    if (dp[final_state] == 0x3f3f3f3f3f3f3f3f) {
        cout << -1;
    } else {
        cout << dp[final_state];
    }
}
