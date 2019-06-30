#include<iostream>
#include<utility>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int N, M;

int abv[MAXN][MAXN];
char col[MAXN][MAXN];

//<col1, col2>
pii flag[MAXN][MAXN];
bool good[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for (int a = 1; a <= N; a++) {
        cin >> (col[a] + 1);
        for (int b = 1; b <= M; b++) {
            if (col[a][b] == col[a - 1][b]) {
                abv[a][b] = abv[a - 1][b] + 1;
            } else {
                abv[a][b] = 1;
            }
        }
    }

    ll ans = 0;
    for (int a = 1; a <= N; a++) {
        for (int b = 1; b <= M; b++) {
            int ht = abv[a][b];
            if (col[a][b] != col[a - ht][b] && 
                a + ht <= N && col[a][b] != col[a + ht][b] &&
                abv[a - ht][b] >= ht &&
                abv[a + ht][b] == ht) {

                good[a][b] = true;
                flag[a][b] = pii(col[a - ht][b], col[a + ht][b]);
            }
        }
        for (int b = 1; b <= M; b++) {
            if (!good[a][b]) {
                continue;
            }
            int nb = b;
            while ( nb + 1 <= M && 
                    flag[a][nb] == flag[a][nb + 1] && 
                    abv[a][nb] == abv[a][nb + 1] && 
                    col[a][nb] == col[a][nb + 1] &&
                    good[a][nb + 1]) {
                nb++;
            }
            ll len = nb - b + 1;
            //cout << a << ", " << b << " has len " << len << endl;
            ans += len * (len + 1) / 2;
            b = nb;
        }
    }
    cout << ans;
}
