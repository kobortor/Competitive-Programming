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

    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        cnt[s[0] - 'a']++;
    }

    int ans = 0;
    for (int a = 0; a < 26; a++) {
        int x = cnt[a] / 2;
        int y = cnt[a] - x;

        ans += x * (x - 1) / 2;
        ans += y * (y - 1) / 2;
    }

    cout << ans;
}
