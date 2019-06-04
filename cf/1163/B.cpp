#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
int cnt[MAXN];
int freq[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    int mx = 0;
    int ans = 1;
    for (int a = 1; a <= N; a++) {
        int x;
        cin >> x;

        cnt[x]++;
        mx = max(mx, cnt[x]);
        freq[cnt[x]]++;
        freq[cnt[x] - 1]--;

        if ((ll)(mx - 1) * (freq[mx - 1] + 1) == a - 1) {
            ans = a;
        } else if (freq[1] != 0 && (mx == 1 || freq[mx] * mx == a - 1)) {
            ans = a;
        }
    }

    cout << ans;
}
