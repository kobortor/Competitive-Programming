#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9;

const ll MAXK = 10;

ll K;
ll C[MAXK];

struct mat {
    ll data[MAXK][MAXK];

    mat(){
        memset(data, 0, sizeof data);
    }

    mat operator*(const mat &m) const {
        mat res;
        for(int a = 0; a < MAXK; a++){
            for(int b = 0; b < MAXK; b++){
                for(int c = 0; c < MAXK; c++){
                    res.data[a][c] += data[a][b] * m.data[b][c];
                    res.data[a][c] %= mod;
                }
            }
        }

        return res;
    }
};

void testcase(){
    mat M, I;

    cin >> K;
    for(int a = 0; a < K; a++){
        cin >> I.data[a][a];
    }
    for(int a = K - 1; a >= 0; a--){
        cin >> C[a];
    }

    for(int a = 0; a < K - 1; a++){
        M.data[a + 1][a] = 1;
    }

    for(int a = 0; a < K; a++){
        M.data[a][K - 1] += C[a];
    }

    ll N;
    cin >> N;
    if(N <= K){
        cout << I.data[N - 1][N - 1] << "\n";
        return;
    } else {
        N -= K;
    }

    while(N){
        if(N & 1){
            I = I * M;
        }

        N >>= 1;
        M = M * M;
    }

    ll ans = 0;
    for(int a = 0; a < K; a++){
        ans += I.data[a][K - 1];
    }
    cout << ans % mod << "\n";
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--){
        testcase();
    }
}
