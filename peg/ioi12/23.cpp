#include<bits/stdc++.h>

using namespace std;
template<typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using maxheap = priority_queue<T>;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;
struct BIT {
    ll data[MAXN];
    BIT() {
        fill(data, data + MAXN, 0);
    }
    void update(int pos, int val) {
        pos += 2;

        while(pos < MAXN) {
            data[pos] += val;
            pos += pos & -pos;
        }
    }
    ll query(int pos) {
        pos += 2;
        ll ans = 0;

        while(pos) {
            ans += data[pos];
            pos -= pos & -pos;
        }

        return ans;
    }
} knightCnt;

struct rangeBIT {
    BIT toadd, tomult;
    void update(int l, int r, ll val) {
        tomult.update(l, val);
        tomult.update(r + 1, -val);
        toadd.update(l, -val * (l - 1));
        toadd.update(r + 1, val * r);
    }
    ll query(int pos) {
        return tomult.query(pos) * pos + toadd.query(pos);
    }
    ll query(int l, int r) {
        return query(r) - query(l - 1);
    }
} HLD;

int N, C, R;

vector<int> adj[MAXN];
int knights[MAXN];
int S[MAXN], E[MAXN];

set<pii> nodes;
int cnt, tot;

int depth[MAXN];
int deepest[MAXN];
int hvson[MAXN];
int top[MAXN];
int id[MAXN];
int par[MAXN];

void dfs1(int pos) {
    deepest[pos] = depth[pos];
    hvson[pos] = -1;

    for(int i : adj[pos]) {
        par[i] = pos;
        depth[i] = depth[pos] + 1;
        dfs1(i);

        if(hvson[pos] == -1 || deepest[i] > deepest[hvson[pos]]) {
            hvson[pos] = i;
            deepest[pos] = deepest[hvson[pos]] + 1;
        }
    }
}

int cntid = 1;
void dfs2(int pos, int tp) {
    id[pos] = cntid++;
    top[pos] = tp;

    if(hvson[pos] != -1) {
        dfs2(hvson[pos], tp);
    }

    for(int i : adj[pos]) {
        if(i != hvson[pos]) {
            dfs2(i, i);
        }
    }
}

int ansL[MAXN];
int ansR[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    cin >> N >> C >> R;

    for(int a = 0; a < N - 1; a++) {
        cin >> knights[a];
    }

    for(int a = 0; a < N; a++) {
        knightCnt.update(a, 1);
        nodes.insert({a, a});
    }

    tot = N, cnt = N;

    for(int a = 0; a < C; a++) {
        cin >> S[a] >> E[a];
        int lo = 0, hi = N - 1;

        while(lo <= hi) {
            int mid = (lo + hi) / 2;

            if(knightCnt.query(mid) <= S[a]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        auto iter = nodes.lower_bound({lo, -1});

        for(int b = S[a]; b <= E[a]; b++) {
            auto tmp = iter++;
            adj[cnt].push_back(tmp->second);
            knightCnt.update(tmp->first, -1);
            nodes.erase(tmp);
        }

        knightCnt.update(lo, 1);
        nodes.insert({lo, cnt});
        cnt++;
    }

    int lastKnight = cnt - 1;
    par[lastKnight] = -1;
    dfs1(lastKnight);
    dfs2(lastKnight, lastKnight);

    for(int a = 0; a < N; a++) {
        int lastDep = depth[a];
        int pos = a;

        while(pos != -1) {
            if(HLD.query(id[top[pos]], id[pos]) == 0) {
                lastDep = depth[top[pos]];
                pos = par[top[pos]];
            } else {
                int lo = id[top[pos]], hi = id[pos] + 1;

                while(lo <= hi) {
                    int mid = (lo + hi) / 2;

                    if(HLD.query(mid, id[pos]) != 0) {
                        lo = mid + 1;
                    } else {
                        hi = mid - 1;
                    }
                }

                lastDep -= (id[pos] + 1) - lo;

                if(pos == a) {
                    lastDep++;
                }

                break;
            }
        }

        ansL[a] = depth[a] - lastDep;

        if(a != N - 1 && knights[a] > R) {
            int pos = a;

            while(pos != -1) {
                HLD.update(id[top[pos]], id[pos], 1);
                pos = par[top[pos]];
            }
        }
    }

    for(int a = 0; a < MAXN; a++) {
        HLD.tomult.data[a] = 0;
        HLD.toadd.data[a] = 0;
    }

    for(int a = N - 1; a >= 0; a--) {
        int lastDep = depth[a];
        int pos = a;

        while(pos != -1) {
            if(HLD.query(id[top[pos]], id[pos]) == 0) {
                lastDep = depth[top[pos]];
                pos = par[top[pos]];
            } else {
                int lo = id[top[pos]], hi = id[pos] + 1;

                while(lo <= hi) {
                    int mid = (lo + hi) / 2;

                    if(HLD.query(mid, id[pos]) != 0) {
                        lo = mid + 1;
                    } else {
                        hi = mid - 1;
                    }
                }

                lastDep -= (id[pos] + 1) - lo;

                if(pos == a) {
                    lastDep++;
                }

                break;
            }
        }

        ansR[a] = depth[a] - lastDep;

        if(a != 0 && knights[a - 1] > R) {
            int pos = a;

            while(pos != -1) {
                HLD.update(id[top[pos]], id[pos], 1);
                pos = par[top[pos]];
            }
        }
    }

    int best = -1;
    int bestPos = -1;

    for(int a = 0; a < N; a++) {
        if(min(ansL[a], ansR[a]) > best) {
            best = min(ansL[a], ansR[a]);
            bestPos = a;
        }
    }

    cout << bestPos;
}
