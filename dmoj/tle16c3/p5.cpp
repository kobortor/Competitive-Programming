#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 355;

int R, C;

int cnt[MAXN];
bool vis[MAXN][MAXN][MAXN];
void dfs(int r, int c, int sz){
    if(r <= 0 || c <= 0 || r + sz - 1 > R || c + sz - 1 > C) return;
    if(vis[r][c][sz]) return;

    vis[r][c][sz] = true;

    cnt[sz]--;

    dfs(r, c, sz + 1);
    dfs(r, c - 1, sz + 1);
    dfs(r - 1, c, sz + 1);
    dfs(r - 1, c - 1, sz + 1);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> R >> C;
    for(int a = 0; a <= min(R, C); a++){
        cnt[a] = (R - a + 1) * (C - a + 1);
    }
    int M;
    cin >> M;
    while(M--){
        int r, c;
        cin >> r >> c;
        dfs(r, c, 1);
        for(int a = MAXN - 1;; a--){
            if(cnt[a]){
                cout << a << "\n";
                break;
            }
        }
    }
}
