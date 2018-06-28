#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1 << 22;

int N, M;

bool marked[MAXN];
bool vis[MAXN * 2];

void dfs(int pos){
    vis[pos] = true;

    if(pos < MAXN){
        if(!vis[pos + MAXN]){
            dfs(pos + MAXN);
        }
    } else {
        int val = pos - MAXN;
        int inv = (1 << N) - val - 1;

        for(int a = 0; a < N; a++){
            int nxt = (val | (1 << a)) + MAXN;
            if(!(val & (1 << a)) && !vis[nxt]){
                dfs(nxt);
            }
        }

        if(marked[inv] && !vis[inv]){
            dfs(inv);
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 0; a < M; a++){
        int x;
        cin >> x;
        marked[x] = true;
    }

    for(int a = 0; a < (1 << N); a++){
    }

    int ans = 0;
    for(int a = 0; a < (1 << N); a++){
        if(marked[a] && !vis[a]){
            dfs(a);
            ans++;
        }
    }

    cout << ans;
}
