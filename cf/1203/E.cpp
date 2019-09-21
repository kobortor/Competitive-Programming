#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int cnt[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    while (n--) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    for (int a = 1; a + 1 < MAXN; a++) {
        if (!cnt[a] && cnt[a + 1]) {
            cnt[a + 1]--;
            cnt[a]++;
        } else if (cnt[a] >= 2) {
            cnt[a + 1]++;
            cnt[a]--;
        }
    }

    int ans = 0;
    for (int a = 0; a < MAXN; a++) {
        ans += !!cnt[a];
    }

    cout << ans;
}
