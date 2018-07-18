#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 21;

ll N, M, K;
ll grid[MAXN][MAXN];
map<ll, ll> path1[MAXN][MAXN];
map<ll, ll> path2[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> K;

    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= M; b++){
            cin >> grid[a][b];
        }
    }

    int mid = (N + M) / 2 + 1;

    path1[1][1][0] = 1;
    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= M && a + b + 1 <= mid; b++){
            if(a != N){
                for(pll p : path1[a][b]){
                    path1[a + 1][b][p.first ^ grid[a][b]] += p.second;
                }
            }
            if(b != M){
                for(pll p : path1[a][b]){
                    path1[a][b + 1][p.first ^ grid[a][b]] += p.second;
                }
            }
        }
    }

    path2[N][M][0] = 1;
    for(int a = N; a >= 1; a--){
        for(int b = M; b >= 1 && a + b - 1 >= mid; b--){
            if(a != 1){
                for(pll p : path2[a][b]){
                    path2[a - 1][b][p.first ^ grid[a][b]] += p.second;
                }
            }
            if(b != 1){
                for(pll p : path2[a][b]){
                    path2[a][b - 1][p.first ^ grid[a][b]] += p.second;
                }
            }
        }
    }

    ll ans = 0;
    for(int a = 1; a <= N; a++){
        int b = mid - a;
        if(b < 0 || M < b){
            continue;
        }
        
        for(pll p : path1[a][b]){
            ans += p.second * path2[a][b][K ^ p.first ^ grid[a][b]];
        }
    }
    
    cout << ans;
}
