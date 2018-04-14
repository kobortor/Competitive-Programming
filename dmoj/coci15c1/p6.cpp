#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 10004;
const int MAXV = 104;

int N;
int joke[MAXN];
vector<int> adj[MAXN];

//dp[pos][l][r]
bitset<MAXV> dp[MAXN][MAXV];
bitset<MAXV> allowed[MAXV]; //cannot have a copy for each node due to memory constraints

void dfs(int pos){
    for(int i : adj[pos]){
        dfs(i);
    }
    bitset<MAXV> good;
    good[joke[pos]] = true;

    fill(allowed, allowed + MAXV, 0);
    for(int i : adj[pos]){
        for(int l = 0; l < MAXV; l++){
            allowed[l] |= dp[i][l];
        }
    }

    for(int a = joke[pos] + 1; a < MAXV; a++){
        for(int b = joke[pos]; b < a; b++){
            if(good[b] && allowed[b + 1][a]){
                good[a] = true;
                break;
            }
        }
    }
    for(int a = joke[pos] - 1; a >= 0; a--){
        for(int b = joke[pos]; b > a; b--){
            if(good[b] && allowed[a][b - 1]){
                good[a] = true;
                break;
            }
        }
    }

    for(int a = 0; a <= joke[pos]; a++){
        for(int b = joke[pos]; b < MAXV; b++){
            if(good[a] && good[b]){
                dp[pos][a][b] = true;
            }
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        cin >> joke[a];
        joke[a]--;
    }
    for(int a = 1; a <= N - 1; a++){
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
    }
    dfs(1);
    int ans = 0;
    for(int a = 0; a < MAXV; a++){
        for(int b = a; b < MAXV; b++){
            if(dp[1][a][b]){
                ans++;
            }
        }
    }
    cout << ans;
}
