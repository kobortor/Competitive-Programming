#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;
const int MAXT = 12;

ll virus[MAXT][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, M, S, T;
    cin >> N >> M >> S >> T;
    vector<pii> edges;
    while (M--) {
        pii p;
        cin >> p.first >> p.second;
        edges.push_back(p);
    }

    virus[0][S] = 1;
    for (int i = 1; i <= T; i++) {
        for (pii p : edges) {
            virus[i][p.second] += virus[i - 1][p.first];
            virus[i][p.first] += virus[i - 1][p.second];
        }
    }
    cout << accumulate(virus[T], virus[T] + MAXN, 0ll) << endl;
}
