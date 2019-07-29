#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;
int lpos[MAXN], rpos[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    ll x1, x2;
    cin >> x1 >> x2;

    vector<pll> LR;
    for (int a = 0; a < n; a++) {
        ll k, b;
        cin >> k >> b;
        ll v1 = k * x1 + b;
        ll v2 = k * x2 + b;
        LR.push_back({v1, v2});
    }

    sort(allof(LR));

    for (int a = 1; a < n; a++) {
        if (LR[a].second < LR[a - 1].second) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}
