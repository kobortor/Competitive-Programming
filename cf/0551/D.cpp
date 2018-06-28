#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N, K, L, M;

struct mat{
    ll val[2][2];
    mat(){
        memset(val, 0, sizeof val);
    }
    mat operator*(const mat &m) const {
        mat ans;
        for(int a = 0; a < 2; a++){
            for(int b = 0; b < 2; b++){
                for(int c = 0; c < 2; c++){
                    ans.val[a][b] += val[a][c] * m.val[c][b];
                    ans.val[a][b] %= M;
                }
            }
        }
        return ans;
    }
};

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K >> L >> M;

    mat ident;
    ident.val[0][0] = 1;
    ident.val[1][1] = 1;

    mat mult;
    mult.val[0][0] = 1;
    mult.val[0][1] = 1;
    mult.val[1][0] = 1;

    ll pow2 = 1;
    ll mult2 = 2;
    while(N){
        if(N & 1){
            ident = ident * mult;
            pow2 = pow2 * mult2 % M;
        }
        N >>= 1;
        mult2 = mult2 * mult2 % M;
        mult = mult * mult;
    }

    ll choose = ident.val[0][0] + ident.val[0][1];

    ll ans = 1;
    
    for(int a = 0; a < L; a++){
        if(K & (1ll << a)){
            ans = ans * (pow2 - choose) % M;

        } else {
            ans = ans * choose % M;
        }
        if(ans < 0){
            ans += M;
        }
    }
    for(int a = L; a < 64; a++){
        if(K & (1ll << a)){
            ans = 0;
            break;
        }
    }
    cout << ans % M;
}
