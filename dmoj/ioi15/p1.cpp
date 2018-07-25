#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e7 + 7;

ll cntL[MAXN];
ll cntR[MAXN];

long long delivery(int N, int K, int L, int positions[]){
    ll ans = 1e18;

    int cyc = 0;
    for(int a = 0; a < N; a++){
        cntR[cyc] += (L - positions[a]) * 2;
        cyc = cyc == K - 1 ? 0 : cyc + 1;
    }

    cyc = K - 1;
    for(int a = 0; a < N; a++){
        ans = min(ans, cntL[cyc] + cntR[cyc == K - 1 ? 0 : cyc + 1]);
        ans = min(ans, cntL[cyc] + cntR[cyc == K - 1 ? 0 : cyc + 1] - (L - positions[a]) * 2 + L);

        cyc = cyc == K - 1 ? 0 : cyc + 1;

        cntR[cyc] -= (L - positions[a]) * 2;
        cntL[cyc] += positions[a] * 2;
    }

    return min(ans, cntL[cyc]);
}
