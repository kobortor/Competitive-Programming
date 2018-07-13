#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2005;

int N, K;
int F[MAXN];
int C[MAXN][MAXN];

int dsu[MAXN];
int find(int x){
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

void solve(){
    cin >> N >> K;

    for(int a = 0; a <= N; a++){
        dsu[a] = a;
    }

    for(int a = 1; a <= N; a++){
        cin >> F[a];
    }

    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= N; b++){
            cin >> C[a][b];
        }
        C[0][a] = F[a];
        C[a][0] = F[a];
    }

    vector<pair<int, pii>> edges;
    for(int a = 0; a <= N; a++){
        for(int b = a + 1; b <= N; b++){
            edges.push_back({C[a][b], {a, b}});
        }
    }

    sort(allof(edges));

    ll cost = 0;
    int used = 0;

    vector<pii> used_edges;

    for(pair<int, pii> p : edges){
        int fu = find(p.second.first);
        int fv = find(p.second.second);

        if(fu != fv){
            dsu[fu] = fv;

            cost += p.first;

            if(p.second.first == 0){
                used++;
            } else {
                used_edges.push_back(p.second);
            }
        }
    }

    for(int a = 1; a <= N; a++){
        dsu[a] = a;
    }

    for(pii p : used_edges){
        int fu = find(p.first);
        int fv = find(p.second);

        if(fu != fv) {
            dsu[fu] = fv;
            F[fv] = min(F[fu], F[fv]);

            for(int a = 1; a <= N; a++){
                C[fv][a] = min(C[fu][a], C[fv][a]);
            }
        }
    }

    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;

    for(int a = 1; a <= N; a++){
        if(dsu[a] != a){
            continue;
        }

        for(int b = 1; b <= N; b++){
            if(find(a) == find(b)){
                continue;
            }

            pq.push({C[a][b] - F[a], {a, b}});
        }
    }

    while(used > K){
        pair<int, pii> top = pq.top();
        pq.pop();

        int fu = find(top.second.first);
        int fv = find(top.second.second);

        if(fu != top.second.first || fu == fv){
            continue;
        }

        used--;

        dsu[fu] = fv;
        cost += top.first;

        //guarantee F[fv] <= F[fu]

        for(int a = 1; a <= N; a++){
            if(C[fu][a] < C[fv][a]){
                C[fv][a] = C[fu][a];

                if(find(fv) != find(a)){
                    pq.push({C[fv][a] - F[fv], {fv, a}});
                }
            }
        }
    }

    cout << cost << "\n";
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;

    for(int a = 1; a <= T; a++){
        solve();
    }
}
