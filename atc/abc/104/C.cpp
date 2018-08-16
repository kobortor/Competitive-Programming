#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 11;

int D, G;
int point[MAXN];
int P[MAXN], C[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> D >> G;

    G /= 100;

    for(int a = 1; a <= D; a++){
        cin >> P[a] >> C[a];
        C[a] /= 100;
    }

    int ans = 1e9;
    for(int state = 0; state < (2 << D); state += 2){
        int tot = 0;
        int solved = 0;
        for(int a = 1; a <= D; a++){
            if(state & (1 << a)){
                solved += P[a];
                tot += P[a] * a + C[a];
            }
        }

        for(int a = D; a >= 1 && tot < G; a--){
            if(state & (1 << a)){
                continue;
            }

            int diff = (G - tot + a - 1) / a;
            solved += min(diff, P[a]);
            tot += min(diff, P[a]) * a;
        }

        ans = min(ans, solved);
    }

    cout << ans;
}
