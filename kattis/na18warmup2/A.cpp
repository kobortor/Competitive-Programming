#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;
const int MAXW = 2e8 + 5;

int N, D;

struct frog {
    int l, w, h;
} frogs [MAXN];

int dp[MAXW];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> D;

    for(int a = 0; a < N; a++){
        cin >> frogs[a].l;
        cin >> frogs[a].w;
        cin >> frogs[a].h;
    }

    sort(frogs, frogs + N, [](frog a, frog b){ return a.w < b.w; });

    memset(dp, 0xafafafaf, sizeof dp);
    dp[MAXW - 1] = 0;

    int maxabv = 0;
    int prvcap = MAXW - 1;
    int ans = 0;

    for(int a = N - 1; a >= 0; a--){
        while(prvcap > 2 * frogs[a].w - 1){
            maxabv = max(maxabv, dp[prvcap]);
            prvcap--;
        }

        int maxht = 0;
        dp[2 * frogs[a].w - 1] = max(dp[2 * frogs[a].w - 1], maxabv);
        for(int b = frogs[a].w; b < 2 * frogs[a].w; b++){
            maxht = max(maxht, dp[b]);
            dp[b - frogs[a].w] = max(dp[b - frogs[a].w], dp[b] + frogs[a].h);
        }

        if(maxht + frogs[a].l > D){
            ans++;
        }
    }

    cout << ans << endl;
}
