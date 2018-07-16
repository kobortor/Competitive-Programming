#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2005;

double ans[MAXN][MAXN], chance[MAXN][MAXN];
bool row[MAXN], col[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    while(M--){
        int r, c;
        cin >> r >> c;

        row[r] = true;
        col[c] = true;
    }

    int nr = count(row, row + MAXN, true);
    int nc = count(col, col + MAXN, true);

    ans[nr][nc] = 0;
    chance[nr][nc] = 1;
    for(int r = nr; r <= N; r++){
        for(int c = nc; c <= N; c++){
            if((r == N && c == N) || chance[r][c] == 0){
                continue;
            }
            ans[r][c] /= chance[r][c];
            double back_chance = (double)(r * c) / (N * N);
            double expected_moves = 1 / (1 - back_chance);

            //only row
            if(r != N){
                double mv = (double)(N - r) * c / (N * N - r * c);
                ans[r + 1][c] += (ans[r][c] + expected_moves) * mv * chance[r][c];
                chance[r + 1][c] += chance[r][c] * mv;
            }

            //only col
            if(c != N){
                double mv = (double)r * (N - c) / (N * N - r * c);
                ans[r][c + 1] += (ans[r][c] + expected_moves) * mv * chance[r][c];
                chance[r][c + 1] += chance[r][c] * mv;
            }

            //both
            if(r != N && c != N){
                double mv = (double)(N - r) * (N - c) / (N * N - r * c);
                ans[r + 1][c + 1] += (ans[r][c] + expected_moves) * mv * chance[r][c];
                chance[r + 1][c + 1] += chance[r][c] * mv;

            }
        }
    }

    cout << fixed << setprecision(15) << ans[N][N];
}
