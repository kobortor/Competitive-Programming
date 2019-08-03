#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool used[105];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, L, R;
    cin >> n >> L >> R;

    for (int a = 2; a <= n; a++) {
        int l, r;
        cin >> l >> r;
        fill(used + l, used + r, true);
    }

    cout << count(used + L, used + R, false);
}
