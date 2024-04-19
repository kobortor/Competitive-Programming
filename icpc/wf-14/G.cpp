#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

#define rep(i, lo, hi) for (int i = lo; i < hi; i++)
#define all(x) (x).begin(), (x).end()

struct TwoSat {
    int N;
    vector<vi> gr;
    vi values;

    TwoSat(int n = 0): N(n), gr(2*n) {}

    void clear() {
        for (vi &v : gr) v.clear();
    }

    void either(int f, int j) {
        f = max(2*f, -1-2*f);
        j = max(2*j, -1-2*j);
        gr[f].push_back(j^1);
        gr[j].push_back(f^1);
    }
    void unequal(int f, int j) {
        f = max(2*f, -1-2*f);
        j = max(2*j, -1-2*j);
        // gr[f].push_back(j^1);
        // gr[j^1].push_back(f);
        gr[j].push_back(f^1);
        gr[f^1].push_back(j);
    }

    vi val, comp, z; int time = 0;
    int dfs(int i) {
        int low = val[i] = ++time, x; z.push_back(i);
        for (int e : gr[i]) if (!comp[e]) {
            low = min(low, val[e] ?: dfs(e));
        }

        if (low == val[i]) do {
            x = z.back(); z.pop_back();
            comp[x] = low;
            if (values[x >> 1] == -1) {
                values[x >> 1] = x&1;
            }
        } while (x != i);
        return val[i] = low;
    }
    bool solve() {
        values.assign(N, -1);
        val.assign(2 * N, 0); comp = val;
        rep(i, 0, 2*N) if (!comp[i]) dfs(i);

        rep(i, 0, N) if (comp[2*i] == comp[2*i+1]) return 0;
        return 1;
    }
};

const int MAXN = 205;
int dist[MAXN][MAXN];

#define DEBUG

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;

#ifdef DEBUG 
    n = 200;
#else
    cin >> n;
#endif

    vector<int> uniq_dist;
    uniq_dist.push_back(0);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            #ifdef DEBUG
            dist[i][j] = i * n + j;
            #else
            cin >> dist[i][j];
            #endif
            dist[j][i] = dist[i][j];
            uniq_dist.push_back(dist[i][j]);
        }
    }

    sort(all(uniq_dist));
    uniq_dist.erase(unique(all(uniq_dist)), uniq_dist.end());

    int ans = 2e9+1;
    for (int idA = 0, idB = uniq_dist.size(); idA < uniq_dist.size() && idA <= idB; idA++) {
        cout << idA << endl;
        int dA = uniq_dist[idA];

        vector<int> last_solve;

        TwoSat ts(n);
        while (idB - 1 >= idA) {
            int dB = uniq_dist[idB - 1];
            ts.clear();

            // true if in A
            for (int i = 1; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    if (dist[i][j] <= dA) {
                        // ok either way
                    } else if (dist[i][j] <= dB) {
                        // must be in B
                        ts.either(i-1, j-1);
                    } else {
                        ts.unequal(i-1, j-1);
                    }
                }
            }
            if (ts.solve()) {
                idB--;
            } else {
                break;
            }
        }
        if (idB != uniq_dist.size()) {
            int dB = uniq_dist[idB];
            ans = min(ans, dA + dB);
        }
    }
    cout << ans << endl;
}
