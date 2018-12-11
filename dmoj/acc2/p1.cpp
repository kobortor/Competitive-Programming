#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;
const int MAXQ = 1e5 + 5;

int N, Q;

ll base[MAXN][MAXN];
ll mat[MAXN][MAXN];
ll tmp[MAXN][MAXN];

ll out[MAXQ];

vector<pair<int, pii>> queries[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    memset(mat, 0x3f, sizeof mat);
    for(int a = 1; a <= N; a++){
        mat[a][a] = 0;
        for(int b = 1; b <= N; b++){
            cin >> base[a][b];
            if(base[a][b] == 0){
                base[a][b] = 1e15;
            }
        }
    }

    for(int k = 1; k <= N; k++){
        for(int a = 1; a <= N; a++){
            for(int b = 1; b <= N; b++){
                base[a][b] = min(base[a][b], base[a][k] + base[k][b]);
            }
        }
    }

    cin >> Q;

    for(int a = 1; a <= Q; a++){
        int s, t, d;
        cin >> s >> t >> d;
        queries[d].push_back({a, {s, t}});
    }

    for(int day = 1; day <= N; day++){
        memset(tmp, 0x3f, sizeof tmp);
        for(int a = 1; a <= N; a++){
            for(int b = 1; b <= N; b++){
                tmp[a][b] = mat[a][b]; //just stay there
                for(int c = 1; c <= N; c++){
                    tmp[a][b] = min(tmp[a][b], max(mat[a][c], base[c][b]));
                }
            }
        }

        for(int a = 1; a <= N; a++){
            for(int b = 1; b <= N; b++){
                mat[a][b] = tmp[a][b];
            }
        }
        for(auto au : queries[day]){
            out[au.first] = mat[au.second.first][au.second.second];
        }
    }

    for(int a = 1; a <= Q; a++){
        if(out[a] > 1e14){
            cout << "0\n";
        } else {
            cout << out[a] << "\n";
        }
    }
}
