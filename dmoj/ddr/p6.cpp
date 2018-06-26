#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 6;
const ll mod = 1e9 + 7;

struct mat {
    ll data[MAXN][MAXN];

    mat(){
        memset(data, 0, sizeof data);
    }

    mat operator*(const mat &m) const {
        mat res;

        for(int a = 0; a < MAXN; a++){
            for(int b = 0; b < MAXN; b++){
                for(int c = 0; c < MAXN; c++){
                    res.data[a][b] += data[a][c] * m.data[c][b];
                    res.data[a][b] %= mod;
                }
            }
        }

        return res;
    }
};

ll qpow(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y & 1){
            ans = ans * x % mod;
        }

        y >>= 1;
        x = x * x % mod;
    }

    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    mat M;
    M.data[0][1] = 4;
    M.data[1][2] = 2;
    M.data[2][3] = 1;
    M.data[3][4] = 1;
    M.data[4][4] = 4;

    M.data[1][1] = 2;

    M.data[2][1] = 2;
    M.data[2][2] = 1;

    M.data[3][1] = 2;
    M.data[3][2] = 1;

    mat ident;

    for(int a = 0; a < MAXN; a++){
        ident.data[a][a] = 1;
    }

    ll N;
    cin >> N;

    ll ans = qpow(4, N);

    while(N){
        if(N & 1){
            ident = ident * M;
        }

        N >>= 1;
        M = M * M;
    }

    ans -= ident.data[0][4];
    if(ans < 0){
        ans += mod;
    }

    assert(0 <= ans && ans < mod);

    cout << ans << "\n";
}
