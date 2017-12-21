#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(ll N, ll targ){
    ll lo = max(1ll, targ - N);
    ll hi = min((targ - 1) / 2, N - 1);
    return max(0ll, hi - lo + 1);
}

int main() {
    ll N;
    cin >> N;

    string limit = to_string(2 * N);
    fill(limit.begin(), limit.end(), '9');

    ll ans = 0;
    for(char c = '0'; c <= '9'; c++){
        limit[0] = c;
        ans += solve(N, stoll(limit));
    }
    cout << ans;
}