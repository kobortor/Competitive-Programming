#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 205;

int N, D1, C1, D2, C2;
int cost[MAXN];

vector<int> adj[MAXN];

int value (vector<int> v) {
    int ans = 0;
    for (int i : v) {
        ans += cost[i];
    }
    return ans;
}

struct node {
    int id, value, dep, group;
    node(int i, int v, int d, int g) : id(i), value(v), dep(d), group(g) {}
    bool operator< (const node &n) const { return value < n.value; }
};

void listnodes (int pos, int par, vector<int> &v) {
    v.push_back(pos);
    for (int i : adj[pos]) {
        if (i == par) continue;
        listnodes(i, pos, v);
    }
}

void listdep (int pos, int par, int dep, int group, vector<node> &v) {
    v.push_back(node(pos, cost[pos], dep, group));
    for (int i : adj[pos]) {
        if (i == par) continue;
        
        listdep(i, pos, dep + 1, group, v);
    }
}

pair<int, vector<int>> help_solve (const vector<node> &vec, int C, int D) {
    int tmpans = 0;
    vector<int> used;

    vector<node> atdep;
    for (node n : vec) {
        if (n.dep < D / 2) {
            tmpans += n.value;
            used.push_back(n.id);
        } else if (n.dep == D / 2) {
            atdep.push_back(n);
        }
    }

    sort(allof(atdep));
    reverse(allof(atdep));
    bool diverse = false;
    for (int i = 0; i < C && i < (int)atdep.size(); i++) {
        tmpans += atdep[i].value;
        used.push_back(atdep[i].id);
        if (atdep[i].group != atdep[0].group) {
            diverse = true;
        }
    }

    if (!diverse) {
        if (C >= (int)atdep.size()) return {0, {}};
        tmpans -= atdep[C - 1].value;
        used.pop_back();

        auto iter = find_if(atdep.begin() + C, atdep.end(), [&](const node &n){return n.group != atdep[0].group;});
        if (iter == atdep.end()) return {0, {}};

        tmpans += iter->value;
        used.push_back(iter->id);
    }

    return {tmpans, used};
}

pair<int, vector<int>> solve (vector<int> nodelist, int D, int C) {
    pair<int, vector<int>> best = {0, {}};
    if (D == 0) {
        pii soln = pii(-1, -1);
        for (int i : nodelist) soln = max(soln, pii(cost[i], i));
        
        return {soln.first, {soln.second}};
    } else {
        for (int center : nodelist) {
            if (D % 2 == 0) {
                vector<node> dep;
                dep.push_back(node(center, cost[center], 0, -1));
                for (int i : adj[center]) listdep(i, center, 1, i, dep);

                best = max(best, help_solve(dep, C, D));
            } else {

                for (int nxt : adj[center]) {
                    vector<node> dep;
                    listdep(center, nxt, 0, 1, dep);
                    listdep(nxt, center, 0, 2, dep);

                    best = max(best, help_solve(dep, C, D));
                }
            }
        }
    }
    
    return best;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> D1 >> C1 >> D2 >> C2;

    if (D1 != 0 && C1 == 1) {
        cout << -1;
        return 0;
    }

    if (D2 != 0 && C2 == 1) {
        cout << -1;
        return 0;
    }

    int tot = 0;
    for (int a = 1; a <= N; a++) {
        cin >> cost[a];
        tot += cost[a];
    }

    for (int a = 1; a <= N - 1; a++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    pair<int, pair<vector<int>, vector<int>>> best = {0, {{}, {}}};
    for (int center = 1; center <= N; center++) {
        pair<int, vector<int>> seen1 = {0, {}}, seen2 = {0, {}};
        for (int i : adj[center]) {
            adj[i].erase(find(allof(adj[i]), center));

            vector<int> nodes;
            listnodes(i, -1, nodes);

            pair<int, vector<int>> res1 = solve(nodes, D1, C1);
            pair<int, vector<int>> res2 = solve(nodes, D2, C2);

            if (res1.first != 0 && seen2.first != 0) {
                best = max(best, {res1.first + seen2.first, {res1.second, seen2.second}});
            }

            if (res2.first != 0 && seen1.first != 0) {
                best = max(best, {res2.first + seen1.first, {res2.second, seen1.second}});
            }

            seen1 = max(seen1, res1);
            seen2 = max(seen2, res2);
        }

        for (int i : adj[center]){
            adj[i].push_back(center);
        }
    }

    if (best.first == 0) {
        cout << -1;
    } else {
        vector<int> lst;
        lst.insert(lst.end(), allof(best.second.first));
        lst.insert(lst.end(), allof(best.second.second));

        cout << tot - best.first << "\n";
        for (int a = 1; a <= N; a++) {
            if (find(allof(lst), a) == lst.end()) {
                cout << a << " ";
            }
        }
    }
}
