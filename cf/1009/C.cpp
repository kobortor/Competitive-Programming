#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

ll N, M;

ll change[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll sum = 0;

    cin >> N >> M;

    while(M--){
        ll x, d;
        cin >> x >> d;
        sum += x * N;

        if(d < 0){
            ll lft = N / 2;
            ll rht = N - lft - 1;
            sum += lft * (lft + 1) / 2 * d;
            sum += rht * (rht + 1) / 2 * d;
        } else {
            sum += N * (N - 1) / 2 * d;
        }
    }

    cout << fixed << setprecision(15) << (double)sum / N;
}
