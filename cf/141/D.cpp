#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, L;

struct ramp {
    int begin, tm, end;
};

vector<ramp> ramps;
vector<int> uniq;

int best[2 * MAXN + 2];
int prv[2 * MAXN + 2];
int prvramp[2 * MAXN + 2];
vector<pii> adj[2 * MAXN + 2];
vector<pii> adj2[2 * MAXN + 2];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> L;

    uniq.push_back(0);
    uniq.push_back(L);
    for(int a = 0; a < N; a++){
        int x, d, t, p;
        cin >> x >> d >> t >> p;
        ramp r;
        r.begin = x - p;
        r.tm = t + p;
        r.end = x + d;

        ramps.push_back(r);

        if(0 <= r.begin){
            uniq.push_back(r.begin);
            uniq.push_back(r.end);
        }
    }
    sort(uniq.begin(), uniq.end());
    uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());

    for(int a = 1; a < (int)uniq.size(); a++){
        adj[a - 1].push_back({a, uniq[a] - uniq[a - 1]});
        adj[a].push_back({a - 1, uniq[a] - uniq[a - 1]});
    }
    for(int a = 0; a < (int)ramps.size(); a++){
        ramp &r = ramps[a];
        if(r.begin < 0){
            continue;
        }
        r.begin = lower_bound(uniq.begin(), uniq.end(), r.begin) - uniq.begin();
        r.end = lower_bound(uniq.begin(), uniq.end(), r.end) - uniq.begin();

        adj2[r.begin].push_back({r.end, a});
    }

    memset(best, 0x3f, sizeof best);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    while(!pq.empty()){
        pii top = pq.top();
        pq.pop();
        for(pii p : adj[top.second]){
            if(top.first + p.second < best[p.first]){
                prv[p.first] = top.second;
                prvramp[p.first] = -1;

                best[p.first] = top.first + p.second;
                pq.push({best[p.first], p.first});
            }
        }
        for(pii p : adj2[top.second]){
            int cost = ramps[p.second].tm;
            if(top.first + cost < best[p.first]){
                prv[p.first] = top.second;
                prvramp[p.first] = p.second;

                best[p.first] = top.first + cost;
                pq.push({best[p.first], p.first});
            }
        }
    }
    cout << best[uniq.size() - 1] << "\n";
    int idx = uniq.size() - 1;

    vector<int> used;
    while(idx != 0){
        if(prvramp[idx] != -1){
            used.push_back(prvramp[idx]);
        }
        idx = prv[idx];
    }

    cout << used.size() << "\n";
    while(!used.empty()){
        cout << used.back() + 1 << " ";
        used.pop_back();
    }
}
