#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1505;

//N is rows
//M is cols
int N, M, K;

int arr[MAXN][MAXN];

int maxUL[MAXN][MAXN];
int maxUR[MAXN][MAXN];
int maxBL[MAXN][MAXN];
int maxBR[MAXN][MAXN];

int get_sq(int r, int c){
    r--;
    c--;

    return arr[r + K][c + K] - arr[r][c + K] - arr[r + K][c] + arr[r][c];
}

void set_mx(int &orig, int v1, int v2){
    orig = max(orig, max(v1, v2));
}

int hor[MAXN];
int ver[MAXN];

int dpH[MAXN][4];
int dpV[MAXN][4];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> K;
    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= M; b++){
            cin >> arr[a][b];
            arr[a][b] += arr[a][b - 1];

        }
        for(int b = M; b >= 1; b--){
            arr[a][b] += arr[a - 1][b];
        }
    }

    for(int a = 1; a + K - 1 <= N; a++){
        for(int b = 1; b + K - 1 <= M; b++){
            int val = get_sq(a, b);
            maxUL[a + K - 1][b + K - 1] = val;
            maxUR[a + K - 1][b] = val;
            maxBL[a][b + K - 1] = val;
            maxBR[a][b] = val;

            hor[a + K - 1] = max(hor[a + K - 1], val);
            ver[b + K - 1] = max(ver[b + K - 1], val);
        }
    }

    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= M; b++){
            set_mx(maxUL[a][b], maxUL[a-1][b], maxUL[a][b-1]);
        }
    }

    for(int a = 1; a <= N; a++){
        for(int b = M; b >= 1; b--){
            set_mx(maxUR[a][b], maxUR[a-1][b], maxUR[a][b+1]);
        }
    }

    for(int a = N; a >= 1; a--){
        for(int b = 1; b <= M; b++){
            set_mx(maxBL[a][b], maxBL[a+1][b], maxBL[a][b-1]);
        }
    }

    for(int a = N; a >= 1; a--){
        for(int b = M; b >= 1; b--){
            set_mx(maxBR[a][b], maxBR[a+1][b], maxBR[a][b+1]);
        }
    }

    int best = 0;

    for(int a = K; a <= N; a++){
        for(int b = 1; b < 4; b++){
            dpH[a][b] = max(dpH[a - 1][b], dpH[a - K][b - 1] + hor[a]);
            dpH[a][b] = max(dpH[a][b], dpH[a][b - 1]);
        }
    }
    best = max(best, dpH[N][3]);

    for(int a = K; a <= M; a++){
        for(int b = 1; b < 4; b++){
            dpV[a][b] = max(dpV[a - 1][b], dpV[a - K][b - 1] + ver[a]);
            dpV[a][b] = max(dpV[a][b], dpV[a][b - 1]);
        }
    }
    best = max(best, dpV[M][3]);

    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= M; b++){
            int UL = maxUL[a][b];
            int UR = maxUR[a][b+1];
            int BL = maxBL[a+1][b];
            int BR = maxBR[a+1][b+1];

            best = max(best, UL + UR + maxBR[a+1][1]); //2 up
            best = max(best, UR + BR + maxUL[N][b]); //2 right
            best = max(best, BL + BR + maxUR[a][1]); //2 bottom
            best = max(best, UL + BL + maxUR[N][b+1]); //2 left
        }
    }

    cout << best;
}

