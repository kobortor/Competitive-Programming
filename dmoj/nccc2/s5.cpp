#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;
const int MAXQ = 1e5 + 5;

struct edge {
    int u, v, c;
    bool operator<(const edge &ee) const {
        return c < ee.c;
    }
};

int dsu[MAXN];
int find(int x){
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

int N, M, Q;
vector<edge> orig;

int query[MAXQ][4];
int ans[MAXQ];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 0; a < M; a++){
        edge e;
        cin >> e.u >> e.v >> e.c;
        orig.push_back(e);
    }

    cin >> Q;
    for(int a = 0; a < Q; a++){
        cin >> query[a][0];
        cin >> query[a][1];
        cin >> query[a][2];
        if(query[a][0] == 2){
            cin >> query[a][3];
        }
    }

    int qidx = 0;

    while(qidx < Q){
        if(query[qidx][0] == 1){
            orig[query[qidx][1] - 1].c = query[qidx][2];
            qidx++;
        }
        vector<pair<edge, int>> quest;
        while(qidx < Q && query[qidx][0] == 2){
            edge e;
            e.u = query[qidx][1];
            e.v = query[qidx][2];
            e.c = query[qidx][3];
            quest.push_back({e, qidx});
            qidx++;
        }

        for(int a = 1; a <= N; a++){
            dsu[a] = a;
        }

        sort(allof(quest));

        vector<edge> avail = orig;
        sort(allof(avail));

        while(!quest.empty()){
            edge qq;
            int id;
            tie(qq, id) = quest.back();
            quest.pop_back();

            while(!avail.empty() && avail.back().c >= qq.c){
                int fu = find(avail.back().u);
                int fv = find(avail.back().v);
                
                if(fu != fv){
                    dsu[fu] = fv;
                }

                avail.pop_back();
            }
            ans[id] = find(qq.u) == find(qq.v);
        }
    }
    for(int a = 0; a < Q; a++){
        if(query[a][0] == 2){
            cout << ans[a] << "\n";
        }
    }
}
