#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

ll N, M, Q;

set<pll> ropes[MAXN];
map<ll, vector<pll>> mp[MAXN];

vector<pll> adj[2 * MAXN];
ll dist[2 * MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> Q;

    while(M--){
        ll A, B, L;
        cin >> A >> B >> L;

        if(A > B){
            swap(A, B);
        }

        ropes[A].insert({B, L});
        mp[A][B]; //create it
    }

    vector<pll> starts;

    while(Q--){
        ll T, A, B, X;
        cin >> T >> A >> B >> X;

        ll len;
        
        if(A > B){
            len = ropes[B].lower_bound({A, 0})->second;
            X = len - X;
            swap(A, B);
        } else {
            len = ropes[A].lower_bound({B, 0})->second;
        }

        if(X == 0){
            starts.push_back({A, T});
        } else if (X == len){
            starts.push_back({B, T});
        } else {
            mp[A][B].push_back({X, T});
        }
    }

    int origN = N;
    for(int a = 1; a <= origN; a++){
        for(auto au : mp[a]){
            ll len = ropes[a].lower_bound({au.first, 0})->second;
            vector<pll> &vec = au.second;
            sort(allof(vec));

            int prv = 0;
            int prvid = a;

            for(int i = 0; i < (int)vec.size(); i++){
                if(vec[i].first == prv){
                    continue;
                } else {
                    N++;

                    adj[prvid].push_back({N, vec[i].first - prv});
                    adj[N].push_back({prvid, vec[i].first - prv});

                    starts.push_back({N, vec[i].second});

                    prv = vec[i].first;
                    prvid = N;
                }
            }

            adj[prvid].push_back({au.first, len - prv});
            adj[au.first].push_back({prvid, len - prv});
        }
    }

    memset(dist, 0x3f, sizeof dist);

    priority_queue<pll, vector<pll>, greater<pll>> pq;

    for(pll p : starts){
        if(p.second < dist[p.first]){
            dist[p.first] = p.second;
            pq.push({p.second, p.first});
        }
    }

    while(!pq.empty()){
        pll top = pq.top();
        pq.pop();

        for(pll p : adj[top.second]){
            if(top.first + p.second < dist[p.first]){
                dist[p.first] = top.first + p.second;
                pq.push({dist[p.first], p.first});
            }
        }
    }

    ll ans = 0;
    for(int a = 1; a <= N; a++){
        for(pll p : adj[a]){
            if(dist[p.first] >= dist[a]){
                ans = max(ans, 2 * (dist[a] + p.second) - (dist[a] + p.second - dist[p.first]));
            }
        }
    }

    cout << ans / 2;
    if(ans & 1){
        cout << ".5";
    }
}
