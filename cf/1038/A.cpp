#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int cnt[26];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, k;
    string s;
    cin >> n >> k >> s;

    for (char c : s) cnt[c - 'A']++;

    int mn = *min_element(cnt, cnt + k);

    int ans = n;
    for (int a = 0; a < k; a++) {
        ans -= cnt[a] - mn;
    }

    cout << ans;
}
