#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, M;
vector<pii> edges[MAXN];

map<pii, int> prv;

pii queries[MAXN];
int ans[MAXN];

bool vis[MAXN];
int dsu[MAXN];

int find(int x){
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    for(int a = 1; a <= N; a++){
        dsu[a] = a;
    }

    for(int a = 1; a <= M; a++){
        int u, v, c;
        cin >> u >> v >> c;
        edges[c].push_back({u, v});
    }

    int Q;
    cin >> Q;
    for(int a = 1; a <= Q; a++){
        int u, v;
        cin >> u >> v;

        if(u > v){
            swap(u, v);
        }

        if(prv.count({u, v})){
            queries[a] = {-1, prv[pii(u, v)]};
        } else {
            prv[pii(u, v)] = a;
            queries[a] = pii(u, v);
        }
    }

    for(int a = 1; a <= M; a++){
        vector<int> nodes;

        for(pii p : edges[a]){
            int u = find(p.first);
            int v = find(p.second);

            nodes.push_back(p.first);
            nodes.push_back(p.second);

            dsu[u] = v;
        }

        sort(allof(nodes));
        nodes.erase(unique(allof(nodes)), nodes.end());

        if((int)edges[a].size() < 500){
            //brute force N^2

            for(int i = 0; i < (int)nodes.size(); i++){
                for(int j = i + 1; j < (int)nodes.size(); j++){
                    if(find(nodes[i]) != find(nodes[j])){
                        continue;
                    }

                    pii p = {nodes[i], nodes[j]};

                    if(prv.count(p)){
                        ans[prv[p]]++;
                    }
                }
            }
        } else {
            //check all

            for(auto &p : prv){
                if(find(p.first.first) == find(p.first.second)){
                    ans[p.second]++;
                }
            }
        }

        for(int i : nodes){
            vis[i] = false;
            dsu[i] = i;
        }
    }

    for(int a = 1; a <= Q; a++){
        if(queries[a].first == -1){
            cout << ans[queries[a].second] << "\n";
        } else {
            cout << ans[a] << "\n";
        }
    }
}
