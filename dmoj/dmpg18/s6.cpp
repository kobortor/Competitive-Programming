#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, M;

vector<int> adj[MAXN];

int disc[MAXN], low[MAXN], cnt = 1;

pii ans = pii(1e9, 0);
void tarjan(int pos){
    disc[pos] = low[pos] = cnt++;

    vector<int> children;
    for(int i : adj[pos]){
        if(disc[i] == 0){
            int start = cnt;
            tarjan(i);
            low[pos] = min(low[pos], low[i]);
            if(low[i] >= disc[pos]){
                children.push_back(cnt - start);
            }
        } else {
            low[pos] = min(low[pos], disc[i]);
        }
    }
    if(pos == 1 && (int)children.size() >= 2){
        int tmp = 0;
        for(int i : children){
            tmp = max(tmp, i);
        }
        ans = min(ans, pii(tmp, -pos));
    }
    if(pos != 1 && !children.empty()){
        int tmp = 0;
        int abv = N - 1;
        for(int i : children){
            tmp = max(tmp, i);
            abv -= i;
        }
        ans = min(ans, pii(max(tmp, abv), -pos));
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    while(M--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    tarjan(1);
    if(ans.second == 0){
        cout << "-1 -1";
    } else {
        cout << -ans.second << " " << ans.first;
    }
}
