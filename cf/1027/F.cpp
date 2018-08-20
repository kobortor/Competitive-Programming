#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e6 + 6;

int N;
pii exam[MAXN];
int dsu[MAXN];
int sz[MAXN];
vector<int> uniq;

int find(int x){
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        cin >> exam[a].first >> exam[a].second;
        uniq.push_back(exam[a].first);
        uniq.push_back(exam[a].second);
    }

    for(int a = 1; a <= 2 * N; a++){
        dsu[a] = a;
        sz[a] = 1;
    }

    sort(allof(uniq));
    uniq.erase(unique(allof(uniq)), uniq.end());

    vector<pii> edges;
    int bad = 0;
    int start = 0;

    for(int a = 1; a <= N; a++){
        exam[a].first = lower_bound(allof(uniq), exam[a].first) - uniq.begin() + 1;
        exam[a].second = lower_bound(allof(uniq), exam[a].second) - uniq.begin() + 1;

        start = max(start, exam[a].first);
        edges.push_back(pii(exam[a].second, exam[a].first));

        sz[exam[a].first]--;
        if(sz[exam[a].first] == -1){
            bad++;
        }
    }

    if(bad == 0){
        cout << uniq[start - 1];
        return 0;
    }

    sort(allof(edges));

    for(pii p : edges){
        int u, v;
        tie(u, v) = p;
        int fu = find(u);
        int fv = find(v);

        if(fu != fv){
            bad -= (sz[fu] < 0);
            bad -= (sz[fv] < 0);

            dsu[fu] = fv;
            sz[fv] += sz[fu];

            bad += (sz[fv] < 0);
        }

        if(bad == 0){
            cout << uniq[max(start, p.first) - 1];
            return 0;
        }
    }

    cout << -1;
}
