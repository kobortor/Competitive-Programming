#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int n, m;
int r[MAXN], c[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for (int a = 0; a < n; a++) {
        string s;
        cin >> s;
        for (int b = 0; b < m; b++) {
            if (s[b] == '*') r[a]++, c[b]++;
        }
    }

    cout << (find(r, r + MAXN, 1) - r + 1) << " " << (find(c, c + MAXN, 1) - c + 1);
}
