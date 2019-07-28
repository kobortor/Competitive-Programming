#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    vector<pii> v(3);
    for (pii &p : v) {
        cin >> p.first >> p.second;
    }

    cout << "3\n";
    for (int a = 0; a < 3; a++) {
        int x, y;
        tie(x, y) = v[a];
        for (int b = 0; b < 3; b++) {
            x += v[b].first - v[a].first;
            y += v[b].second - v[a].second;
        }
        cout << x << " " << y << "\n";
    }
}
