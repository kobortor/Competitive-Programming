#include<bits/stdc++.h>

#pragma region template code
using namespace std;
template<typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using maxheap = priority_queue<T>;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const int INF = 0x3f3f3f3f;

const int MAXN = 80;
char grid[MAXN][MAXN];
int dp[MAXN][MAXN][2];

struct QUERY {
    int r, c, tp, dist;
    QUERY(int R, int C, int TP, int DIST) {
        r = R;
        c = C;
        tp = TP;
        dist = DIST;
    }
    bool operator>(const QUERY &qq) const {
        return dist > qq.dist;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //cin.tie(0);
    //cin.sync_with_stdio(0);
#endif

    for(int board = 1; true; board++) {
        int W, H;
        cin >> W >> H;

        if(W == 0 && H == 0) {
            return 0;
        }

        cout << "Board #" << board << ":\n";

        fill(grid[0], grid[0] + W + 2, ' ');
        fill(grid[H + 1], grid[H + 1] + W + 2, ' ');

        for(int a = 1; a <= H; a++) {
            cin.ignore();
            grid[a][0] = ' ';
            for(int i = 1; i <= W; i++) {
                cin >> noskipws >> grid[a][i];
            }
            grid[a][W + 1] = ' ';
        }
        cin >> skipws;
        for(int query = 1; true; query++) {
            int r1, r2, c1, c2;
            cin >> c1 >> r1 >> c2 >> r2;
            if(c1 == 0 && c2 == 0 && r1 == 0 && r2 == 0) {
                break;
            }
            cout << "Pair " << query << ": ";

            for(int a = 0; a <= H + 1; a++) {
                for(int b = 0; b <= W + 1; b++) {
                    dp[a][b][0] = INF;
                    dp[a][b][1] = INF;
                }
            }

            minheap<QUERY> pq;
            dp[r1][c1][0] = 1;
            dp[r1][c1][1] = 1;
            pq.push({r1, c1, 0, 1}); //horizontal
            pq.push({r1, c1, 1, 1}); //vertical

            while(!pq.empty()) {
                QUERY q = pq.top();
                //printf("Move to %i %i %i %i\n", q.r, q.c, q.tp, q.dist);
                pq.pop();

                if(!(q.r == r1 && q.c == c1) && grid[q.r][q.c] == 'X') {
                    continue;
                }

                if(q.r == 2 && q.c == 4){
                    int x=  3;
                }

                if(q.tp == 0) { //horizontal
                    if(dp[q.r][q.c][1] > q.dist + 1) {
                        dp[q.r][q.c][1] = q.dist + 1;
                        pq.push({q.r, q.c, 1, q.dist + 1});
                    }

                    if(q.c != 0 && dp[q.r][q.c - 1][0] > q.dist) {
                        dp[q.r][q.c - 1][0] = q.dist;
                        pq.push({q.r, q.c - 1, 0, q.dist});
                    }

                    if(q.c != W + 1 && dp[q.r][q.c + 1][0] > q.dist) {
                        dp[q.r][q.c + 1][0] = q.dist;
                        pq.push({q.r, q.c + 1, 0, q.dist});
                    }
                } else { //vertical
                    if(dp[q.r][q.c][0] > q.dist + 1) {
                        dp[q.r][q.c][0] = q.dist + 1;
                        pq.push({q.r, q.c, 0, q.dist + 1});
                    }

                    if(q.r != 0 && dp[q.r - 1][q.c][1] > q.dist) {
                        dp[q.r - 1][q.c][1] = q.dist;
                        pq.push({q.r - 1, q.c, 1, q.dist});
                    }

                    if(q.r != H + 1 && dp[q.r + 1][q.c][1] > q.dist) {
                        dp[q.r + 1][q.c][1] = q.dist;
                        pq.push({q.r + 1, q.c, 1, q.dist});
                    }
                }
            }

            if(dp[r2][c2][0] == INF && dp[r2][c2][1] == INF) {
                cout << "impossible.\n";
            } else {
                cout << min(dp[r2][c2][0], dp[r2][c2][1]) << " segments.\n";
            }
        }
        cout << "\n";
    }
}
