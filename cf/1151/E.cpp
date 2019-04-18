#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

ll N;
ll A[MAXN];

//p - q + s = c + 1
//p - q + 1 = c + 1
//p - q = c

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for (int a = 0; a < N; a++) {
        cin >> A[a];
    }

    ll ans = 0;
    for (int a = 0; a < N; a++) {
        ans += A[a] * (N - A[a] + 1);
    }

    for (int a = 0; a + 1 < N; a++) {
        ll v1 = A[a];
        ll v2 = A[a + 1];
        if (v1 > v2) {
            swap(v1, v2);
        }

        ans -= v1 * (N - v2 + 1);
    }

    cout << ans;
}
