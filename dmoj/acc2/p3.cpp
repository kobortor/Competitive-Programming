#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int dep[MAXN];
vector<pii> adj[MAXN];
pair<int, pii> jump[MAXN][20];

pii merge(pii p1, pii p2){
    if(p1.first < p2.first){
        return {p2.first, max(p1.first, p2.second)};
    } else {
        return {p1.first, max(p1.second, p2.first)};
    }
}

void dfs(int pos, int par){
    for(int a = 0; a + 1 < 20 && jump[pos][a].first; a++){
        jump[pos][a + 1].first = jump[jump[pos][a].first][a].first;
        jump[pos][a + 1].second = merge(jump[pos][a].second,
                                        jump[jump[pos][a].first][a].second);
    }

    for(pii p : adj[pos]){
        if(p.first == par){
            continue;
        }
        dep[p.first] = dep[pos] + 1;
        jump[p.first][0] = {pos, pii(p.second, -1)};
        dfs(p.first, pos);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    for(int a = 1; a <= N - 1; a++){
        int ai, bi, wi;
        cin >> ai >> bi >> wi;
        adj[ai].push_back({bi, wi});
        adj[bi].push_back({ai, wi});
    }

    dfs(1, 0);

    int Q;
    cin >> Q;

    while(Q--){
        int s, t;
        cin >> s >> t;

        pii soln = pii(-1, -1);

        if(dep[s] < dep[t]){
            swap(s, t);
        }

        for(int a = 0; a < 20; a++){
            if((dep[s] - dep[t]) & (1 << a)){
                soln = merge(soln, jump[s][a].second);
                s = jump[s][a].first;
            }
        }

        if(s != t){
            for(int a = 19; a >= 0; a--){
                if(jump[s][a].first != jump[t][a].first){
                    soln = merge(soln, jump[s][a].second);
                    soln = merge(soln, jump[t][a].second);

                    s = jump[s][a].first;
                    t = jump[t][a].first;
                }
            }

            soln = merge(soln, jump[s][0].second);
            soln = merge(soln, jump[t][0].second);
        }

        cout << soln.second << "\n";
    }
}
