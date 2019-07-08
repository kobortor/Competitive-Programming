#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 998244353;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    string s;
    cin >> n >> s;

    ll fr = 1, bk = n - 1;

    while (fr < n && s[fr] == s[fr - 1]) fr++;
    while (bk > 0 && s[bk - 1] == s[bk]) bk--;

    if (fr == n) {
        cout << n * (n - 1) / 2 % mod;
    } else if (s[0] == s.back()) {
        cout << (fr + 1) * (n - bk + 1) % mod;
    } else {
        cout << ((fr + 1) + (n - bk + 1) - 1) % mod;
    }
}
