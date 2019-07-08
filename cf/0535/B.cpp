#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s;
    cin >> s;

    ll ans = 0;
    for (int a = 0; a < (int)s.size(); a++) {
        ans = ans * 2 + (s[a] == '7');
    }

    for (int a = 0; a < (int)s.size(); a++) {
        ans += 1 << a;
    }

    cout << ans;
}
