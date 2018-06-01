#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5e4 + 4;

ll N, X;

ll len[MAXN];
ll lim[MAXN];

ll num_req(double imp){
    ll ans = 0;
    for(int a = 0; a < N; a++){
        /*
        K = new lim
        len / K - len / (K + 1) >= imp
        len >= imp * K ^ 2 + imp * K
        0 >= imp * K ^ 2 + imp * K - len

        The largest K that satisfies this is:

        K = (-imp + sqrt(imp * imp + 4 * imp * len)) / (2 * imp)

        So add 1 to fail it
        */

        ll K = (-imp + sqrt(imp * imp + 4 * imp * len[a])) / (2 * imp) + 1;

        ans += max(0ll, K - lim[a]);
        if(ans > X){
            return X + 1;
        }
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> X;
    for(int a = 0; a < N; a++){
        cin >> len[a];
    }
    for(int a = 0; a < N; a++){
        cin >> lim[a];
    }

    double lo = 1e-15, hi = 10000;
    for(int cyc = 0; cyc < 100; cyc++){
        double mid = (lo + hi) / 2;
        if(num_req(mid) < X){
            hi = mid;
        } else {
            lo = mid;
        }
    }

    double imp = hi;

    for(int a = 0; a < N; a++){
        ll K = (-imp + sqrt(imp * imp + 4 * imp * len[a])) / (2 * imp) + 1;

        if(K > lim[a]){
            X -= K - lim[a];
            lim[a] = K;
        }
    }

    priority_queue<pair<double, int>> pq;
    for(int a = 0; a < N; a++){
        pq.push({(double)len[a] / (lim[a] * (lim[a] + 1)), a});
    }

    while(X --> 0){
        pair<double, int> top = pq.top();
        pq.pop();

        lim[top.second]++;
        pq.push({(double)len[top.second] / (lim[top.second] * (lim[top.second] + 1)), top.second});
    }

    double ans = 0;
    for(int a = 0; a < N; a++){
        ans += (double)len[a] / lim[a];
    }
    cout << fixed << setprecision(9) << ans;
}
