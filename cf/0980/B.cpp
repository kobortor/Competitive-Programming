#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int N, K;
char grid[4][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;

    for(int a = 0; a < 4; a++){
        fill(grid[a], grid[a] + N, '.');
        grid[a][N] = 0;
    }

    if(K % 2 == 0){
        for(int a = 1; a <= K / 2; a++){
            grid[1][a] = '#';
            grid[2][a] = '#';
        }
    } else {
        if(K <= N - 2){
            K = (K + 1) / 2;
            for(int a = 0; a < K; a++) {
                grid[1][N / 2 - a] = '#';
                grid[1][N / 2 + a] = '#';
            }
        } else {
            K++;
            for(int a = 1; a <= K / 2; a++){
                grid[1][a] = '#';
                grid[2][a] = '#';
            }
            grid[1][2] = '.';
        }
    }
    cout << "YES\n";
    for(int a = 0; a < 4; a++){
        cout << grid[a] << endl;
    }
}
