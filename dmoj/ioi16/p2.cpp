#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 4e5 + 5;

int dsu[MAXN];
int prefix[MAXN];

int find(int x){
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

long long plan_roller_coaster(int n, int *s, int *t){
    vector<int> uniq;
    for(int a = 0; a < n; a++){
        uniq.push_back(s[a]);
        uniq.push_back(t[a]);
    }

    sort(allof(uniq));
    uniq.erase(unique(allof(uniq)), uniq.end());

    for(int a = 0; a < (int)uniq.size(); a++){
        dsu[a] = a;
    }

    for(int a = 0; a < n; a++){
        int is = lower_bound(allof(uniq), s[a]) - uniq.begin();
        int it = lower_bound(allof(uniq), t[a]) - uniq.begin();

        prefix[is]++;
        prefix[it]--;

        int fu = find(is);
        int fv = find(it);
        dsu[fu] = fv;
    }

    vector<pii> edges;
    ll res = 0;
    for(int a = 0; a < (int)uniq.size() - 1; a++){
        prefix[a + 1] += prefix[a];
        if(prefix[a] > 1){
            res += ll(prefix[a] - 1) * ll(uniq[a + 1] - uniq[a]);
            dsu[find(a)] = find(a + 1);
        } else if(prefix[a] < 1){
            dsu[find(a)] = find(a + 1);
        } else {
            edges.push_back({uniq[a + 1] - uniq[a], a});
        }
    }
    sort(allof(edges));

    for(const pii &p : edges){
        int f1 = find(p.second);
        int f2 = find(p.second + 1);
        if(f1 != f2){
            res += p.first;
            dsu[f1] = f2;
        }
    }
    return res;
}
