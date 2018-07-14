#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

ll N, H;
ll B[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> H;

    ll maxA = 0;
    for(int a = 0; a < N; a++){
        ll A;
        cin >> A >> B[a];
        maxA = max(maxA, A);
    }
    sort(B, B + N);
    reverse(B, B + N);

    ll ans = (H + maxA - 1) / maxA;
    for(int a = 0; a < N; a++){
        H -= B[a];
        ans = min(ans, max(0ll, (H + maxA - 1) / maxA) + a + 1);
    }
    cout << ans;
}
