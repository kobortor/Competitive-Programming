#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

int N;
int dep[MAXN];
list<int> lst[MAXN];
vector<int> adj[MAXN];
pii best[MAXN];
int ans[MAXN];

void dfs(int pos, int par){
    int children = 0;

    for(int i : adj[pos]){
        children++;
        if(i == par){
            continue;
        }

        dep[i] = dep[pos] + 1;
        dfs(i, pos);

        lst[i].push_front(0);
    }

    lst[pos].push_back(1);
    best[pos] = pii(1, -dep[pos]);

    for(int i : adj[pos]){
        if(i == par){
            continue;
        }

        if(lst[i].size() > lst[pos].size()){
            lst[pos].swap(lst[i]);
            swap(best[pos], best[i]);
        }
    }

    for(int i : adj[pos]){
        if(i == par){
            continue;
        }

        auto cur = lst[pos].begin();
        auto iter = lst[i].begin();
        int idx = 0;

        while(iter != lst[i].end()){
            *cur += *iter;
            best[pos] = max(best[pos], pii(*cur, -(dep[pos] + idx)));

            cur++;
            iter++;
            idx++;
        }
    }

    ans[pos] = (-best[pos].second) - dep[pos];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N - 1; a++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    for(int a = 1; a <= N; a++){
        cout << ans[a] << "\n";
    }
}
