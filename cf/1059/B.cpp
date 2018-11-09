#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M;

char grid[1005][1005];
char out[1005][1005];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    for(int a = 0; a < N; a++){
        cin >> grid[a];
        fill(out[a], out[a] + 1005, '.');
    }

    for(int a = 0; a + 2 < N; a++){
        for(int b = 0; b + 2 < M; b++){
            bool good = true;
            good &= grid[a + 0][b + 0] == '#';
            good &= grid[a + 0][b + 1] == '#';
            good &= grid[a + 0][b + 2] == '#';
            good &= grid[a + 1][b + 0] == '#';
            good &= grid[a + 1][b + 2] == '#';
            good &= grid[a + 2][b + 0] == '#';
            good &= grid[a + 2][b + 1] == '#';
            good &= grid[a + 2][b + 2] == '#';

            if(good){
                out[a + 0][b + 0] = '#';
                out[a + 0][b + 1] = '#';
                out[a + 0][b + 2] = '#';
                out[a + 1][b + 0] = '#';
                out[a + 1][b + 2] = '#';
                out[a + 2][b + 0] = '#';
                out[a + 2][b + 1] = '#';
                out[a + 2][b + 2] = '#';
            }
        }
    }

    for(int a = 0; a < N; a++){
        for(int b = 0; b < M; b++){
            if(grid[a][b] != out[a][b]){
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
}
