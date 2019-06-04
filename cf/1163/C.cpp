#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

ll gcd(ll a, ll b) {
    a = abs(a);
    b = abs(b);
    while (a % b) {
        a %= b;
        swap(a, b);
    }
    return b;
}

ll N;
pii pole[MAXN];

set<ll> ver;
set<ll> hor;
set<pair<pii, ll>> dia;
map<pii, set<ll>> slope;

ll choose2(ll n) {
    return n * (n - 1) / 2;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for (int a = 1; a <= N; a++) {
        cin >> pole[a].first >> pole[a].second;
    }

    for (int a = 1; a <= N; a++) {
        for (int b = a + 1; b <= N; b++) {
            if (pole[a].first == pole[b].first) {
                ver.insert(pole[a].first); //vertical
            } else if (pole[a].second == pole[b].second) {
                hor.insert(pole[a].second); //horizontal
            } else {
                ll dx = pole[a].first - pole[b].first;
                ll dy = pole[a].second - pole[b].second;
                
                ll g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                if (dx < 0) {
                    dx *= -1;
                    dy *= -1;
                }

                ll offset = pole[a].second * dx - pole[a].first * dy;
                dia.insert({{dx, dy}, offset});
                slope[pii(dx, dy)].insert(offset);
            }
        }
    }

    ll ans = choose2(ver.size() + hor.size() + dia.size());
    ans -= choose2(ver.size());
    ans -= choose2(hor.size());
    for (auto au : slope) {
        ans -= choose2(au.second.size());
    }

    cout << ans;
}
