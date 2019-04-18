#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;
int N;
vector<pll> vec;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for (int a = 0; a < N; a++) {
        pll p;
        cin >> p.first >> p.second;
        vec.push_back(p);
    }

    sort(allof(vec), [](pll a, pll b) {return a.first - a.second > b.first - b.second;});

    ll ans = 0;
    for (int a = 0; a < N; a++) {
        ans += vec[a].first * a;
        ans += vec[a].second * (N - a - 1);
    }

    cout << ans;
}
