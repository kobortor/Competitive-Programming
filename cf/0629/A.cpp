#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    vector<string> v(n);
    for (string &s : v) cin >> s;

    int ans = 0;
    for (int a = 0; a < n; a++) {
        int rr = 0, cc = 0;
        for (int b = 0; b < n; b++) {
            rr += v[a][b] == 'C';
            cc += v[b][a] == 'C';
        }

        ans += rr * (rr - 1) / 2;
        ans += cc * (cc - 1) / 2;
    }

    cout << ans;
}
