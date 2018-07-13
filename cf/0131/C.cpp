#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 65;

int N, M, T;

ll nck[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> T;

    nck[0][0] = 1;
    for(int a = 1; a < MAXN; a++){
        nck[a][0] = 1;
        for(int b = 1; b <= a; b++){
            nck[a][b] = nck[a - 1][b - 1] + nck[a - 1][b];
        }
    }

    ll ans = 0;
    for(int B = 4; B <= N && T - B >= 1; B++){
        ans += nck[N][B] * nck[M][T - B];
    }

    cout << ans;
}
