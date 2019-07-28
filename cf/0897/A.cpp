#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m;
    string s;
    cin >> n >> m >> s;

    while (m--) {
        int l, r;
        char c1, c2;
        cin >> l >> r >> c1 >> c2;
        for (int a = l - 1; a < r; a++) {
            if (s[a] == c1) s[a] = c2;
        }
    }

    cout << s;
}
