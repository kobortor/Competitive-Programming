#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

ll cnt[3];
ll tmp[3];
ll arr[3];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n, l, r;
    cin >> n >> l >> r;

    cnt[0] = (r + 3) / 3 - (l + 3 - 1) / 3;
    cnt[1] = (r + 2) / 3 - (l + 2 - 1) / 3;
    cnt[2] = (r + 1) / 3 - (l + 1 - 1) / 3;

    arr[0] = 1;
    while (n--) {
        for (int a = 0; a < 3; a++) {
            tmp[a] = 0;
            for (int b = 0; b < 3; b++) {
                tmp[a] += arr[b] * cnt[(3 + a - b) % 3] % mod;
            }
        }
        for (int a = 0; a < 3; a++) {
            arr[a] = tmp[a] % mod;
        }
    }

    cout << arr[0];
}
