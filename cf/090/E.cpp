#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5005;

int N, M;

string grid[MAXN];

struct udlr {
    int u = -1, d = -1, l = -1, r = -1;
};

udlr orig[MAXN];
udlr adj[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    for(int a = 0; a < N; a++){
        cin >> grid[a];
    }

    for(int a = 0; a < N; a++){
        for(int b = 0; b < M; b++){
            if(grid[a][b] == '.'){
                continue;
            }

            for(int c = a - 1; c >= 0; c--) {
                if(grid[c][b] != '.'){
                    orig[a * M + b].u = c * M + b;
                    break;
                }
            }
            for(int c = a + 1; c < N; c++) {
                if(grid[c][b] != '.'){
                    orig[a * M + b].d = c * M + b;
                    break;
                }
            }

            for(int c = b - 1; c >= 0; c--) {
                if(grid[a][c] != '.'){
                    orig[a * M + b].l = a * M + c;
                    break;
                }
            }
            for(int c = b + 1; c < M; c++) {
                if(grid[a][c] != '.'){
                    orig[a * M + b].r = a * M + c;
                    break;
                }
            }
        }
    }

    int best = 0, bestcnt = 0;
    for(int a = 0; a < N; a++){
        for(int b = 0; b < M; b++){
            if(grid[a][b] == '.'){
                continue;
            }
            copy(orig, orig + N * M, adj);

            int step = 0;
            int cur = a * M + b;

            while(cur != -1){
                int nxt;
                char ch = grid[cur / M][cur % M];
                if(ch == 'U'){
                    nxt = adj[cur].u;
                } else if (ch == 'D'){
                    nxt = adj[cur].d;
                } else if (ch == 'L'){
                    nxt = adj[cur].l;
                } else if (ch == 'R'){
                    nxt = adj[cur].r;
                }

                if(adj[cur].u != -1){
                    adj[adj[cur].u].d = adj[cur].d;
                }
                if(adj[cur].d != -1){
                    adj[adj[cur].d].u = adj[cur].u;
                }
                if(adj[cur].l != -1){
                    adj[adj[cur].l].r = adj[cur].r;
                }
                if(adj[cur].r != -1){
                    adj[adj[cur].r].l = adj[cur].l;
                }

                step++;
                cur = nxt;
            }

            if(step > best){
                best = step;
                bestcnt = 1;
            } else if(best == step){
                bestcnt++;
            }
        }
    }
    cout << best << " " << bestcnt << "\n";
}
