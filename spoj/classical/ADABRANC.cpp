#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, M, Q;

int dsu[MAXN];
int sz[MAXN];

int find(int x){
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

vector<pair<int, pii>> edges, queries;

int out[MAXN * 3];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> Q;

    while(N--){
        dsu[N] = N;
        sz[N] = 1;
    }

    while(M--){
        pair<int, pii> p;
        cin >> p.second.first >> p.second.second >> p.first;
        edges.push_back(p);
    }

    sort(allof(edges));
    reverse(allof(edges));

    for(int a = 0; a < Q; a++){
        pair<int, pii> p;
        cin >> p.second.first >> p.first;
        p.second.second = a;

        queries.push_back(p);
    }

    sort(allof(queries));
    reverse(allof(queries));

    int idx = 0;
    for(pair<int, pii> p : queries){
        while(idx < (int)edges.size() && edges[idx].first >= p.first){
            int fu = find(edges[idx].second.first);
            int fv = find(edges[idx].second.second);

            if(fu != fv){
                dsu[fu] = fv;
                sz[fv] += sz[fu];
            }
            idx++;
        }

        int fi = find(p.second.first);
        out[p.second.second] = sz[fi];
    }
    for(int a = 0; a < Q; a++){
        cout << out[a] << "\n";
    }
}
