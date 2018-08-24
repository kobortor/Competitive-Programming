#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 3e5 + 5;

int N;
pii seg[MAXN];
pii inter[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    inter[0] = pii(-1, 2e9);
    for(int a = 1; a <= N; a++){
        cin >> seg[a].first >> seg[a].second;
        inter[a] = pii(max(inter[a - 1].first, seg[a].first), min(inter[a - 1].second, seg[a].second));
    }

    int ans = 0;
    for(int a = N, L = -1, R = 2e9; a >= 1; a--){
        ans = max(ans, min(R, inter[a - 1].second) - max(L, inter[a - 1].first));
        L = max(L, seg[a].first);
        R = min(R, seg[a].second);
    }
    cout << ans;
}
