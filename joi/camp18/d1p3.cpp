#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 3005;
const ll mod = 1e9 + 7;

int H, W;
int fact[MAXN];
int invfact[MAXN];
int inv2[MAXN];
int choose_col[MAXN][MAXN * 2];

int qpow(int x, int y){
    int ans = 1;
    while(y){
        if(y & 1){
            ans = (ll)ans * x % mod;
        }
        y >>= 1;
        x = (ll)x * x % mod;
    }
    return ans;
}

int inv(int x){
    return qpow(x, mod - 2);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> H >> W;

    fact[0] = 1;
    invfact[0] = 1;
    for(int a = 1; a <= max(H, W); a++){
        fact[a] = (ll)fact[a - 1] * a % mod;
        invfact[a] = inv(fact[a]);
    }

    inv2[0] = 1;
    inv2[1] = inv(2);
    for(int a = 2; a <= max(H, W); a++){
        inv2[a] = ((ll)inv2[a - 1] * inv2[1]) % mod;
    }

    choose_col[0][0] = 1;
    for(int a = 1; a <= W; a++){
        for(int b = 0; b <= a * 2; b++){
            choose_col[a][b] = choose_col[a - 1][b];
            if(b >= 1){
                choose_col[a][b] += (ll)choose_col[a - 1][b - 1] * 4 % mod;
                choose_col[a][b] %= mod;
            }
            if(b >= 2){
                choose_col[a][b] += (ll)choose_col[a - 1][b - 2] * inv2[1] % mod;
                choose_col[a][b] %= mod;
            }
        }
    }

    int ans = 0;
    for(int a = 0; a <= H && 2 * a <= W; a++){
        int remH = H - a;
        int remW = W - 2 * a;

        int nck = (ll)fact[H] * invfact[a] % mod * (ll)invfact[H - a] % mod;
        int mulW = (ll)fact[W] * invfact[remW] % mod * inv2[a] % mod * nck % mod;

        for(int b = 0; b <= remH; b++){
            ans = (ans + (ll)mulW * choose_col[remW][b] % mod * fact[remH] % mod * invfact[remH - b]) % mod;
        }
    }

    cout << (ans - 1 + mod) % mod;
}
