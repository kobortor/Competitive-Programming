#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2005;

int N, P, Q;
int A[MAXN];
int nxts[MAXN];
int nxtl[MAXN];
int dp[MAXN][MAXN];

bool check(int W){
    for(int a = 0, s = 1, l = 1; a + 1 <= N; a++){
        while(s + 1 <= N && A[s + 1] - A[a + 1] + 1 <= W){
            s++;
        }
        while(l + 1 <= N && A[l + 1] - A[a + 1] + 1 <= 2 * W){
            l++;
        }

        nxts[a] = s;
        nxtl[a] = l;
    }

    memset(dp, 0, sizeof dp);

    for(int a = 0; a <= P; a++){
        for(int b = 0; b <= Q; b++){
            if(a){
                dp[a][b] = max(dp[a][b], nxts[dp[a - 1][b]]);
            }

            if(b){
                dp[a][b] = max(dp[a][b], nxtl[dp[a][b - 1]]);
            }

            if(dp[a][b] == N){
                return true;
            }
        }
    }

    return false;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> P >> Q;

    P = min(P, N);
    Q = min(Q, N);

    for(int a = 1; a <= N; a++){
        cin >> A[a];
    }

    sort(A + 1, A + N + 1);

    int lo = 1, hi = 1e9;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(check(mid)){
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo;
}
