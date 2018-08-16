#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 4005;

int N;
int W[MAXN];
int B[MAXN];

struct BIT {
    int data[MAXN];
    void update(int pos, int val){
        while(pos < MAXN){
            data[pos] += val;
            pos += pos & -pos;
        }
    }

    int query(int pos){
        int ans = 0;
        while(pos){
            ans += data[pos];
            pos -= pos & -pos;
        }
        return ans;
    }
} ds;

//[W][B]
int dp[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= 2 * N; a++){
        char C;
        int A;
        cin >> C >> A;
        if(C == 'W'){
            W[A] = a;
        } else {
            B[A] = a;
        }
    }

    memset(dp, 0x3f, sizeof dp);

    dp[1][1] = 0;

    for(int w = 1; w <= N + 1; w++){
        for(int b = 1; b <= N + 1; b++){
            if(w != N + 1){
                dp[w + 1][b] = min(dp[w + 1][b], dp[w][b] + (b + w - 2) - ds.query(W[w]));
            }

            if(b != N + 1){
                dp[w][b + 1] = min(dp[w][b + 1], dp[w][b] + (b + w - 2) - ds.query(B[b]));
                ds.update(B[b], 1);
            }
        }

        for(int b = 1; b <= N; b++){
            ds.update(B[b], -1);
        }

        if(w != N + 1){
            ds.update(W[w], 1);
        }
    }

    cout << dp[N + 1][N + 1];
}
