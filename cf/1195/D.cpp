#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 998244353;

const int MAXD = 22;
int digfreq[MAXD];
ll pow10[MAXD];

ll f (string a, string b) {
    ll ans = 0;
    int step = 0;
    while (!a.empty() || !b.empty()) {
        if (step % 2 == 0) {
            if (b.empty()) {
                ans += pow10[step] * (a.back() - '0');
                ans %= mod;

                a.pop_back();
            } else {
                ans += pow10[step] * (b.back() - '0');
                ans %= mod;

                b.pop_back();
            }
        } else {
            if (a.empty()) {
                ans += pow10[step] * (b.back() - '0');
                ans %= mod;

                b.pop_back();
            } else {
                ans += pow10[step] * (a.back() - '0');
                ans %= mod;

                a.pop_back();
            }
        }
        step++;
    }

    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    pow10[0] = 1;
    for (int a = 1; a < MAXD; a++) {
        pow10[a] = pow10[a - 1] * 10 % mod;
    }

    int n;
    cin >> n;
    
    vector<string> v(n);
    for (string &s : v) {
        cin >> s;
        digfreq[s.size()]++;
    }

    ll ans = 0;
    for (string s : v) {
        string x = "";
        for (int d = 1; d < MAXD; d++) {
            x += '0';
            if (digfreq[d] == 0) continue;

            ans += digfreq[d] * f(s, x);
            ans += digfreq[d] * f(x, s);
            ans %= mod;
        }
    }

    cout << ans;
}
