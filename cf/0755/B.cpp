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
    cin >> n >> m;

    set<string> poland;
    for (int a = 0; a < n; a++) {
        string s;
        cin >> s;
        poland.insert(s);
    }

    int both = 0;
    for (int a = 0; a < m; a++) {
        string s;
        cin >> s;
        if (poland.count(s)) {
            both++;
        }
    }

    int poland_only = n - both;
    int enemy_only = m - both;

    cout << (poland_only + both % 2 > enemy_only ? "YES" : "NO");
}
