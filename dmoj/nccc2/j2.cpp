#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 51;

int N, M;
char grid[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 0; a < N; a++){
        cin >> grid[a];
    }
    for(int t = 0; t < 100; t++){
        for(int a = 0; a < N - 1; a++) {
            for(int b = 0; b < M; b++) {
                if(grid[a][b] == 'o' && grid[a + 1][b] == '.'){
                    swap(grid[a][b], grid[a + 1][b]);
                }
            }
        }
    }
    for(int a = 0; a < N; a++){
        cout << grid[a] << "\n";
    }
}
