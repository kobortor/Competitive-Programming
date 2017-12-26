#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 205;
const int mod = 1e9 + 7;

int nCr[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    nCr[0][0] = 1;
    for(int a = 1; a < MAXN; a++){
        nCr[a][0] = 1;
        for(int b = 1; b <= a; b++){
            nCr[a][b] = (nCr[a - 1][b] + nCr[a - 1][b - 1]) % mod;
        }
    }

    int T;
    cin >> T;
    while(T--){
        int N, M;
        cin >> N >> M;
        cout << nCr[N + M][N] << "\n";
    }
}