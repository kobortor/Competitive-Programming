#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < (b); ++i)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

struct PushRelabel {

    struct Edge {
        int dest, back;
        ll f, c;
    };

    vector<vector<Edge>> g;
    vector<ll> ec;
    vector<Edge*> cur;
    vector<vi> hs; vi H;

    PushRelabel(int n) : g(n), ec(n), cur(n), hs(2 * n), H(n) {}

    void addEdge(int s, int t, ll cap, ll rcap=0) {
        if (s == t) return;
        g[s].push_back({t, sz(g[t]), 0, cap});
        g[t].push_back({s, sz(g[s])-1, 0, rcap});
    }

    void addFlow(Edge &e, ll f) {

        Edge &back = g[e.dest][e.back];
        if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
        e.f += f; e.c -= f; ec[e.dest] += f;
        back.f -= f; back.c += f; ec[back.dest] -= f;

    }

    ll calc(int s, int t) {

        int v = sz(g); H[s] = v; ec[t] = 1;
        vi co(2 * v); co[0] = v - 1;
        rep(i,0,v) cur[i] = g[i].data();
        for (Edge &e : g[s]) addFlow(e, e.c);

        for (int hi = 0;;) {

            while (hs[hi].empty()) if (!hi--) return -ec[s];
            int u = hs[hi].back(); hs[hi].pop_back();
            while (ec[u] > 0) {
                if (cur[u] == g[u].data() + sz(g[u])) {
                    H[u] = 1e9;
                    for (Edge& e : g[u]) if (e.c && H[u] > H[e.dest]+1)
                        H[u] = H[e.dest]+1, cur[u] = &e;
                    if (++co[H[u]], !--co[hi] && hi < v)
                        rep(i,0,v) if (hi < H[i] && H[i] < v)
                            --co[H[i]], H[i] = v + 1;
                    hi = H[u];
                } else if (cur[u]->c && H[u] == H[cur[u]->dest] + 1) {
                    addFlow(*cur[u], min(ec[u], cur[u]->c));
                }
                else ++cur[u];
            }

        }

    }

};

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int s, r, f, t; cin >> s >> r >> f >> t;

    map<string,int> tind;
    int wv = 1;

    auto get_ind = [&](string s) {
        if (tind.find(s) != tind.end()) {
            return tind[s];
        }
        tind[s] = wv;
        wv++;
        return wv - 1;
    };

    vector<int> wtype(s + 1);
    // -1: source
    // 0 : intermediate
    // 1: sink
    vector<int> hr(r + 1), hf(f + 1);
    for (int i = 1; i <= r; i++) {
        string foo; cin >> foo;
        int cind = get_ind(foo);
        wtype[cind] = -1;
        hr[i] = cind;
    }
    for (int i = 1; i <= f; i++) {
        string foo; cin >> foo;
        int cind = get_ind(foo);
        wtype[cind] = 1;
        hf[i] = cind;
    }

    PushRelabel helper(s + 2 + t + t);
    int sink = s + 1 + t + t;

    for (int i = 1; i <= r; i++) {
        helper.addEdge(0, hr[i], 1);
    }
    for (int i = 1; i <= f; i++) {
        helper.addEdge(hf[i], sink, 1);
    }
    for (int i = 1; i <= t; i++) {

        int kk; cin >> kk;
        vector<int> cval;
        for (int j = 0; j < kk; j++) {
            string foo; cin >> foo;
            cval.push_back(get_ind(foo));
        }

        int cvin = s + 2 * (i - 1) + 1;
        int cvout = s + 2 * (i - 1) + 2;

        helper.addEdge(cvin, cvout, 1);

        for (int j : cval) {

            if (wtype[j] <= 0) {
                helper.addEdge(j, cvin, 1);
            }
            if (wtype[j] >= 0) {
                helper.addEdge(cvout, j, 1);
            }

        }

    }

    cout << helper.calc(0, sink) << "\n";

}
