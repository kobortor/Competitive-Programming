#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2005;

int N, M;

struct comp {
    int c, f, v;
} store[MAXN], req[MAXN];

ll dp[MAXN * 50];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> store[a].c;
        cin >> store[a].f;
        cin >> store[a].v;
    }

    cin >> M;

    for(int a = 0; a < M; a++){
        cin >> req[a].c;
        cin >> req[a].f;
        cin >> req[a].v;
    }

    sort(store, store + N, [](const comp &ca, const comp &cb){return ca.f > cb.f;});
    sort(req, req + M, [](const comp &ca, const comp &cb){return ca.f > cb.f;});

    memset(dp, 0xaf, sizeof dp);
    dp[0] = 0;

    for(int a = 0, b = 0; a < M; a++){
        while(b < N && store[b].f >= req[a].f){
            for(int i = MAXN * 50 - 1; i >= store[b].c; i--){
                dp[i] = max(dp[i], dp[i - store[b].c] - store[b].v);
            }
            b++;
        }

        for(int i = 0; i + req[a].c < MAXN * 50; i++){
            dp[i] = max(dp[i], dp[i + req[a].c] + req[a].v);
        }
    }

    cout << *max_element(dp, dp + MAXN * 50);
}
