#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int prefix[26][MAXN];
void testcase() {
    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;
    for (int a = 0; a < N; a++) {
        for (int b = 0; b < 26; b++) {
            prefix[b][a + 1] = prefix[b][a];
        }
        prefix[s[a] - 'A'][a + 1]++;
    }

    int ans = 0;
    while (Q--) {
        int l, r;
        cin >> l >> r;

        int odd = 0;
        for (int a = 0; a < 26; a++) {
            if ((prefix[a][r] - prefix[a][l - 1]) % 2) {
                odd++;
            }
        }

        if (odd <= 1) {
            ans++;
        }
    }

    cout << ans << "\n";
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;
    for (int a = 1; a <= T; a++) {
        cout << "Case #" << a << ": ";
        testcase();
    }
}
