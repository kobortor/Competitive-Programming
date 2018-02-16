#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

ll N, M, P, Q;
ll maxcost = 0;

struct edge {
    int tp;
    int u, v;
    ll c;
    bool operator<(const edge &ee) const{
        return c < ee.c;
    }
};

//if two planets A and B are linked
//then (a, x) being linked with (a, y) is equivalent to (b, x) linked with (b, y)

//if two cities X, Y are linked
//then (a, x) being linked with (b, x) is equivalent to (a, y) being linked with (b, y)

vector<edge> edges;

ll conn1;
ll conn2;
int dsu1[MAXN];
int dsu2[MAXN];
int find1(int x){
    return dsu1[x] == x ? x : dsu1[x] = find1(dsu1[x]);
}
int find2(int x){
    return dsu2[x] == x ? x : dsu2[x] = find2(dsu2[x]);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> P >> Q;

    for(int a = 0; a < MAXN; a++){
        dsu1[a] = a;
        dsu2[a] = a;
    }

    for(int a = 0; a < P; a++){
        edge e;
        e.tp = 0;
        cin >> e.u >> e.v >> e.c;
        e.u--;
        e.v--;

        maxcost += N * e.c;
        edges.push_back(e);
    }
    for(int a = 0; a < Q; a++){
        edge e;
        e.tp = 1;
        cin >> e.u >> e.v >> e.c;
        e.u--;
        e.v--;

        maxcost += M * e.c;
        edges.push_back(e);
    }
    sort(allof(edges));

    ll cost = 0;
    for(edge e : edges){
        if(e.tp == 0){
            //connect cities
            int fu = find1(e.u);
            int fv = find1(e.v);
            if(fu != fv){
                conn1++;
                dsu1[fu] = fv;
                cost += (N - conn2) * e.c;
            }

        } else {
            //connect planets
            int fu = find2(e.u);
            int fv = find2(e.v);

            if(fu != fv){
                conn2++;
                dsu2[fu] = fv;
                cost += (M - conn1) * e.c;
            }
        }
    }
    cout << maxcost - cost;
}
