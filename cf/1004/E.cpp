#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, K;

vector<pii> adj[MAXN];
int incoming[MAXN];

int dist[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;

    if(N == 1){
        cout << 0;
        return 0;
    }

    for(int a = 1; a <= N - 1; a++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});

        incoming[u]++;
        incoming[v]++;
    }

    int remain = N;
    int bad = 0;
    int ans = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int a = 1; a <= N; a++){
        if((int)adj[a].size() == 1){
            pq.push({adj[a][0].second, a});
        }
        if((int)adj[a].size() > 2){
            bad++;
        }
    }

    if(remain <= K && bad == 0){
        cout << ans;
        return 0;
    }


    while(!pq.empty()){
        pii fr = pq.top();
        pq.pop();
        remain--;

        ans = max(ans, fr.first);

        for(pii p : adj[fr.second]){
            if(incoming[p.first] == 0){
                continue;
            }

            dist[p.first] = max(dist[p.first], dist[fr.second] + p.second);
            incoming[p.first]--;
            incoming[fr.second]--;

            if(incoming[p.first] == 2){
                bad--;
            }

            if(incoming[p.first] == 1){
                int worst = dist[p.first];
                for(pii p2 : adj[p.first]){
                    if(incoming[p2.first] >= 1){
                        worst = max(worst, dist[p.first] + p2.second);
                    }
                }

                pq.push({worst, p.first});
            }
        }

        if(remain <= K && bad == 0){
            cout << ans;
            break;
        }
    }
}
