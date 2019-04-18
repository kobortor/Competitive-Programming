#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 505;

int N, M;
int grid[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for (int a = 1; a <= N; a++) { 
        for (int b = 1; b <= M; b++) {
            cin >> grid[a][b];
        }
    }

    int tmp = 0;
    for (int a = 1; a <= N; a++) {
        tmp ^= grid[a][1];
    }

    if (tmp != 0) {
        cout << "TAK\n";
        for (int a = 1; a <= N; a++) {
            cout << "1 ";
        }
        return 0;
    }
    
    for (int a = 1; a <= N; a++) {
        if (*min_element(grid[a] + 1, grid[a] + M + 1)
            != *max_element(grid[a] + 1, grid[a] + M + 1)) {
            cout << "TAK\n";
            for (int b = 1; b < a; b++) {
                cout << "1 ";
            }
            for (int b = 1; b <= M; b++) {
                if (grid[a][b] != grid[a][1]) {
                    cout << b << " ";
                    break;
                }
            }
            for (int b = a + 1; b <= N; b++) {
                cout << "1 ";
            }
            return 0;
        }
    }

    cout << "NIE\n";
}
