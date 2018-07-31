#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int N, M;
char grid[MAXN][MAXN];

int len[MAXN][MAXN];
int prehor[MAXN][MAXN], prever[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 1; a <= N; a++){
        cin >> (grid[a] + 1);
    }

    memset(len, 0x3f, sizeof len);
    for(int a = 0; a <= N + 1; a++){
        int prv = 0;
        for(int b = 1; b <= M; b++){
            if(grid[a][b] == '.'){
                prv = b;
            }

            len[a][b] = min(len[a][b], b - prv - 1);
        }

        prv = M + 1;

        for(int b = M; b >= 1; b--){
            if(grid[a][b] == '.'){
                prv = b;
            }

            len[a][b] = min(len[a][b], prv - b - 1);
        }
    }

    for(int b = 1; b <= M; b++){
        int prv = 0;
        for(int a = 1; a <= N; a++){
            if(grid[a][b] == '.'){
                prv = a;
            }
            len[a][b] = min(len[a][b], a - prv - 1);
        }

        prv = N + 1;
        for(int a = N; a >= 1; a--){
            if(grid[a][b] == '.'){
                prv = a;
            }
            len[a][b] = min(len[a][b], prv - a - 1);
        }
    }

    vector<pair<pii, int>> stars;
    for(int a = 1; a <= N; a++) {
        for(int b = 1; b <= M; b++){
            if(len[a][b] > 0){
                stars.push_back({{a, b}, len[a][b]});
            }
        }
    }

    for(pair<pii, int> p : stars){
        prehor[p.first.first][p.first.second - p.second]++; 
        prehor[p.first.first][p.first.second + p.second + 1]--;

        prever[p.first.first - p.second][p.first.second]++; 
        prever[p.first.first + p.second + 1][p.first.second]--;
    }

    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= M; b++){
            prehor[a][b] += prehor[a][b - 1];
            prever[a][b] += prever[a - 1][b];

            if(!prehor[a][b] && !prever[a][b] && grid[a][b] == '*'){
                cout << -1;
                return 0;
            }
        }
    }

    cout << stars.size() << "\n";

    for(pair<pii, int> p : stars){
        cout << p.first.first << " " << p.first.second << " " << p.second << "\n";
    }
}
