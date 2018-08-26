#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;
const ll mod = 1e9;

ll N;
ll X[MAXN], Y[MAXN];
ll ans = 0;

vector<int> points[MAXN];
vector<pair<pii, int>> blocks[MAXN];
vector<int> adj[MAXN];

bool inter(int l1, int r1, int l2, int r2){
    return max(l1, l2) <= min(r1, r2);
}

ll cnt[MAXN];
ll len[MAXN];
ll sz[MAXN];

void dfs(int pos, int par, ll abv_len, ll abv_sz){
    sz[pos] = cnt[pos];
    len[pos] = 0;

    ans += abv_len * cnt[pos];

    for(int i : adj[pos]){
        if(i == par){
            continue;
        }
        dfs(i, pos, abv_len + abv_sz + len[pos] + sz[pos], abv_sz + sz[pos]);

        len[pos] += len[i] + sz[i];
        sz[pos] += sz[i];
    }
}

void solve(){
    for(int a = 0; a < N; a++){
        points[a].clear();
        blocks[a].clear();
        adj[a].clear();
    }

    for(int a = 0; a < N; a++){
        points[X[a]].push_back(Y[a]);
    }

    int id = 0;
    for(int a = 0; a < N; a++){
        sort(allof(points[a]));
        for(int b = 0; b < (int)points[a].size(); b++){
            int c = b;
            while(c + 1 < (int)points[a].size() && points[a][c + 1] == points[a][c] + 1){
                c++;
            }

            cnt[id] = points[a][c] - points[a][b] + 1;
            blocks[a].push_back({pii(points[a][b], points[a][c]), id++});
            b = c;
        }
    }

    for(int a = 1; a < N; a++){
        int blw = 0;
        for(pair<pii, int> p : blocks[a]){
            while(blw < (int)blocks[a - 1].size() && blocks[a - 1][blw].first.second <= p.first.second){
                if(inter(p.first.first, p.first.second, blocks[a - 1][blw].first.first, blocks[a - 1][blw].first.second)){
                    adj[p.second].push_back(blocks[a - 1][blw].second);
                    adj[blocks[a - 1][blw].second].push_back(p.second);
                }
                blw++;
            }

            if(blw < (int)blocks[a - 1].size() && inter(p.first.first, p.first.second, blocks[a - 1][blw].first.first, blocks[a - 1][blw].first.second)){
                adj[p.second].push_back(blocks[a - 1][blw].second);
                adj[blocks[a - 1][blw].second].push_back(p.second);
            }
        }
    }

    dfs(0, -1, 0, 0);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> X[a] >> Y[a];
    }

    ll minx = *min_element(X, X + N);
    ll miny = *min_element(Y, Y + N);

    for(int a = 0; a < N; a++){
        X[a] -= minx;
        Y[a] -= miny;
    }

    solve();

    for(int a = 0; a < N; a++){
        swap(X[a], Y[a]);
    }

    solve();

    cout << ans % mod;
}
