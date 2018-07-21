#include<bits/stdc++.h>

#pragma region template code
using namespace std;
template<typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using maxheap = priority_queue<T>;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const int INF = 0x3f3f3f3f;


const int MAXN = 1.5e5 + 5;

int N, M, P;
vector<int> nxt[MAXN];
bool ntp[MAXN][2];
bool is_cycle[MAXN][2];
int incoming[MAXN][2];
bool vis[MAXN][2];
bool cycle_vis[MAXN][2];

//refers to P that is not on any cycle
vector<int> distToP[MAXN][2];

int distToCycle[MAXN][2];
pii cycleEnter[MAXN][2];
int cyclePt[MAXN][2];
int cycleLen[MAXN][2];
pii cycleRoot[MAXN][2];

void dfs(int pos, int tp) {
    if(vis[pos][tp]) {
        return;
    }

    vis[pos][tp] = true;

    if(!is_cycle[nxt[pos][tp]][ntp[pos][tp]]) {
        dfs(nxt[pos][tp], ntp[pos][tp]);

        for(int i : distToP[nxt[pos][tp]][ntp[pos][tp]]) {
            distToP[pos][tp].push_back(i + 1);
        }

        distToCycle[pos][tp] = distToCycle[nxt[pos][tp]][ntp[pos][tp]] + 1;
        cycleEnter[pos][tp] = cycleEnter[nxt[pos][tp]][ntp[pos][tp]];
    } else {
        distToCycle[pos][tp] = 1;
        cycleEnter[pos][tp] = {nxt[pos][tp], ntp[pos][tp]};
    }

    if(pos == P) {
        distToP[pos][tp].push_back(0);
    }
}

//counts number of paths without cycle that reach p at .first
map<int, int> paths;

struct cycle {
    int startAt;
    int period;
    int modv;
    cycle(int s, int p, int m) {
        startAt = s;
        period = p;
        modv = m;
    }

    bool operator<(cycle c)const {
        return startAt < c.startAt;
    }
};

vector<pii> queries;
int output[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    cin >> N >> M >> P;

    for(int a = 0; a < M; a++) {
        int x, y;
        cin >> x >> y;

        if(nxt[x].size() < 2) {
            nxt[x].push_back(y);
        }

        if(nxt[y].size() < 2) {
            nxt[y].push_back(x);
        }
    }

    for(int a = 0; a < N; a++) {
        if(nxt[a].size() == 1) {
            nxt[a].push_back(nxt[a][0]);
        }

        for(int b = 0; b < 2; b++) {
            ntp[a][b] = a == nxt[nxt[a][b]][0];
        }
    }


    memset(is_cycle, true, sizeof is_cycle);

    for(int a = 0; a < N; a++) {
        for(int tp = 0; tp < 2; tp++) {
            incoming[nxt[a][tp]][ntp[a][tp]]++;
        }
    }

    queue<pii> q;

    for(int a = 0; a < N; a++) {
        for(int tp = 0; tp < 2; tp++) {
            if(!incoming[a][tp]) {
                q.push({a, tp});
            }
        }
    }

    while(!q.empty()) {
        pii p = q.front();
        q.pop();
        is_cycle[p.first][p.second] = false;
        incoming[nxt[p.first][p.second]][ntp[p.first][p.second]]--;

        if(!incoming[nxt[p.first][p.second]][ntp[p.first][p.second]]) {
            q.push({nxt[p.first][p.second], ntp[p.first][p.second]});
        }
    }

    for(int a = 0; a < N; a++) {
        for(int tp = 0; tp < 2; tp++) {
            if(is_cycle[a][tp] && !cycle_vis[a][tp]) {
                int loc = a, type = tp;
                int idx = 0;

                do {
                    cycle_vis[loc][type] = true;
                    cycleRoot[loc][type] = {a, tp};
                    cyclePt[loc][type] = idx++;
                    tie(loc, type) = pii(nxt[loc][type], ntp[loc][type]);
                } while(loc != a || type != tp);

                do {
                    cycleLen[loc][type] = idx;
                    tie(loc, type) = pii(nxt[loc][type], ntp[loc][type]);
                } while(loc != a || type != tp);
            }
        }
    }

    for(int a = 0; a < N; a++) {
        for(int tp = 0; tp < 2; tp++) {
            if(!is_cycle[a][tp]) {
                dfs(a, tp);
            }
        }
    }

    vector<cycle> cycles;

    for(int a = 0; a < N; a++) {

        if(is_cycle[a][0]) {
            for(int tp = 0; tp < 2; tp++) {
                if(is_cycle[P][tp] && cycleRoot[a][0] == cycleRoot[P][tp]) {
                    int len = cycleLen[P][tp];
                    int diff = cyclePt[P][tp] - cyclePt[a][0];
                    cycles.push_back(cycle(0, len, (diff + len) % len));
                }
            }
        } else {
            for(int i : distToP[a][0]) {
                paths[i]++;
            }

            pii enter = cycleEnter[a][0];

            for(int tp = 0; tp < 2; tp++) {
                if(is_cycle[P][tp] && cycleRoot[enter.first][enter.second] == cycleRoot[P][tp]) {
                    int distTo = distToCycle[a][0];
                    int len = cycleLen[P][tp];
                    int diff = cyclePt[P][tp] - cyclePt[enter.first][enter.second];
                    cycles.push_back(cycle(distTo, len, (distTo + diff + len) % len));
                }
            }
        }
    }

    sort(cycles.begin(), cycles.end());

    int Q;
    cin >> Q;

    for(int a = 0; a < Q; a++) {
        int x;
        cin >> x;
        queries.push_back({x, a});
    }

    sort(queries.begin(), queries.end());

    map<int, map<int, int>> modulos;
    int back = 0;

    for(int a = 0; a < queries.size(); a++) {
        while(back < cycles.size() && cycles[back].startAt <= queries[a].first) {
            modulos[cycles[back].period][cycles[back].modv]++;
            back++;
        }

        ll tmpans = paths[queries[a].first];

        for(auto &au : modulos) {
            tmpans += au.second[queries[a].first % au.first];
        }

        output[queries[a].second] = tmpans;
    }

    for(int a = 0; a < queries.size(); a++) {
        cout << output[a] << " ";
    }
}
