#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 12;
const int MAXW = 101;

int N, M, Q;
int W[MAXN];
int cnt[1 << MAXN];
int ans[1 << MAXN][MAXW];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> Q;
    for(int a = 0; a < N; a++){
        cin >> W[a];
    }
    reverse(W, W + N);

    while(M--){
        bitset<MAXN> bits;
        cin >> bits;
        cnt[bits.to_ulong()]++;
    }

    for(int a = 0; a < (1 << N); a++){
        for(int b = 0; b < (1 << N); b++){
            if(cnt[b] == 0){
                continue;
            }
            int sum = 0;
            for(int c = 0; c < N; c++){
                if((a & (1 << c)) == (b & (1 << c))){
                    sum += W[c];
                }
            }

            if(sum < MAXW){
                ans[a][sum] += cnt[b];
            }
        }

        for(int b = 1; b < MAXW; b++){
            ans[a][b] += ans[a][b - 1];
        }
    }

    while(Q--){
        bitset<MAXN> bits;
        int K;
        cin >> bits >> K;
        cout << ans[bits.to_ulong()][K] << "\n";
    }
}
