#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n;
    cin >> n;

    vector<ll> balls(n);
    for (ll &bi : balls) {
        cin >> bi;
    }

    sort(allof(balls));

    vector<ll> diffs(5001);
    for (ll a = 0; a < n; a++) {
        for (ll b = a + 1; b < n; b++) {
            diffs[balls[b] - balls[a]]++;
        }
    }

    vector<ll> diff2(10001);
    for (ll a = 1; a < 5001; a++) {
        for (ll b = 1; b < 5001; b++) {
            diff2[a + b] += diffs[a] * diffs[b];
        }
    }

    ll cnt = 0;
    ll tot_leq = 0;
    for (ll i = 1; i <= 5000; i++) {
        cnt += diffs[i] * tot_leq;
        tot_leq += diff2[i];
    }

    double ways = n * (n - 1) / 2;
    ways = ways * ways * ways;

    cout << fixed << setprecision(15) << cnt / ways;
}
