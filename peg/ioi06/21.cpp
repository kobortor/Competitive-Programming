#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int N, M;

bool adj[MAXN][MAXN];

/*
-1 - unchecked
0 - not possible
1 - go left
2 - go right
*/
int dp[2][MAXN][MAXN];

int solve(bool tp, int l, int r){
    if(dp[tp][l][r] != -1){
        return dp[tp][l][r];
    }

    if(l == r){
        return dp[tp][l][r] = 1;
    }

    int nl = (l - 1 + N) % N;
    int nr = (r + 1) % N;

    if(tp == 0){
        if(adj[l][nl] && solve(0, nl, r) != 0){
            return dp[tp][l][r] = 1;
        }

        if(adj[l][nr] && solve(1, l, nr) != 0){
            return dp[tp][l][r] = 2;
        }
    } else {
        if(adj[r][nl] && solve(0, nl, r) != 0){
            return dp[tp][l][r] = 1;
        }

        if(adj[r][nr] && solve(1, l, nr) != 0){
            return dp[tp][l][r] = 2;
        }
    }

    return dp[tp][l][r] = 0;
}

vector<int> soln;
void get_soln(bool tp, int l, int r){
    while(l != r){
        if(tp == 0){
            soln.push_back(l);
            if(dp[tp][l][r] == 1){
                tp = 0;
                l = (l - 1 + N) % N;
            } else {
                tp = 1;
                r = (r + 1) % N;
            }
        } else {
            soln.push_back(r);
            if(dp[tp][l][r] == 1){
                tp = 0;
                l = (l - 1 + N) % N;
            } else {
                tp = 1;
                r = (r + 1) % N;
            }
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(dp, -1, sizeof dp);

    cin >> N >> M;

    while(M--){
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        adj[u][v] = true;
        adj[v][u] = true;
    }

    for(int a = 0; a < N; a++){
        if(adj[a][(a + 1) % N]){
            if(solve(0, a, (a + 1) % N) != 0){
                soln.push_back(a + 1);
                get_soln(0, a, (a + 1) % N);
                for(int i : soln){
                    cout << i + 1 << "\n";
                }
                return 0;
            }

            if(solve(1, a, (a + 1) % N) != 0){
                soln.push_back(a);
                get_soln(1, a, (a + 1) % N);
                for(int i : soln){
                    cout << i + 1 << "\n";
                }
                return 0;
            }
        }
    }

    cout << -1;
}
