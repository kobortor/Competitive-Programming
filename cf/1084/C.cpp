#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s;
    cin >> s;

    ll ans = 0;

    int A = 0, B = 1;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'a') {
            A = (A + B) % mod;
            ans = (ans + B) % mod;
        } else if (s[i] == 'b') {
            B = (A + B) % mod;
            A = 0;
        }
    }

    cout << ans;
}
