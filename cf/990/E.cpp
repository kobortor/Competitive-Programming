#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

int N, M, K;
bool block[MAXN];
int prv[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> K;

    while(M--){
        int x;
        cin >> x;
        block[x + 1] = true;
    }

    if(block[1]){
        cout << -1;
        return 0;
    }

    for(int a = 1; a <= N; a++){
        if(block[a]){
            prv[a] = prv[a - 1];
        } else {
            prv[a] = a;
        }
    }

    ll ans = 1e18;
    for(int a = 1; a <= K; a++){
        ll cost = 0;
        cin >> cost;

        ll idx = 1;
        ll steps = 0;
        while(true){
            steps++;
            ll nxt = idx + a;

            if(nxt > N){
                break;
            }
            nxt = prv[nxt];
            if(nxt <= idx){
                steps = -1;
                break;
            } else {
                idx = nxt;
            }
        }

        if(steps != -1){
            ans = min(ans, steps * cost);
        }
    }

    if(ans == 1e18){
        cout << -1;
    } else {
        cout << ans;
    }
}
