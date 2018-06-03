#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 606;

int N;
vector<pii> P1, P2;
int D1, D2;

int col1[MAXN][MAXN];
int col2[MAXN][MAXN];

void dfs1(int r, int c){
    for(pii p : P1){
        int nr = r + p.first;
        int nc = c + p.second;

        if(1 <= nr && nr <= 2 * N && 1 <= nc && nc <= 2 * N && col1[nr][nc] == -1){
            col1[nr][nc] = !col1[r][c];
            dfs1(nr, nc);
        }
    }
}

void dfs2(int r, int c){
    for(pii p : P2){
        int nr = r + p.first;
        int nc = c + p.second;

        if(1 <= nr && nr <= 2 * N && 1 <= nc && nc <= 2 * N && col2[nr][nc] == -1){
            col2[nr][nc] = !col2[r][c];
            dfs2(nr, nc);
        }
    }
}

vector<pii> ans[2][2];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(col1, -1, sizeof col1);
    memset(col2, -1, sizeof col2);

    cin >> N >> D1 >> D2;

    for(int a = -2 * N; a <= 2 * N; a++){
        for(int b = -2 * N; b <= 2 * N; b++){
            if(a * a + b * b == D1){
                P1.push_back({a, b});
            }
            if(a * a + b * b == D2){
                P2.push_back({a, b});
            }
        }
    }

    for(int a = 1; a <= 2 * N; a++){
        for(int b = 1; b <= 2 * N; b++){
            if(col1[a][b] == -1){
                col1[a][b] = 0;
                dfs1(a, b);
            }
            if(col2[a][b] == -1){
                col2[a][b] = 0;
                dfs2(a, b);
            }           
            ans[col1[a][b]][col2[a][b]].push_back({a, b});
        }
    }

    for(int a = 0; a < 2; a++){
        for(int b = 0; b < 2; b++){
            if((int)ans[a][b].size() >= N * N){
                for(int c = 0; c < N * N; c++){
                    cout << ans[a][b][c].first - 1 << " " << ans[a][b][c].second - 1 << "\n";
                }
                return 0;
            }
        }
    }
}
