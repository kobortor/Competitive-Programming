#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int n;
int cnt[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int a = 1; a <= n; a++) {
        cin >> cnt[a];
    }

    int m;
    cin >> m;

    while (m--) {
        int x, y;
        cin >> x >> y;

        cnt[x + 1] += cnt[x] - y;
        cnt[x - 1] += y - 1;
        cnt[x] = 0;
    }

    for (int a = 1; a <= n; a++) {
        cout << cnt[a] << "\n";
    }
}
