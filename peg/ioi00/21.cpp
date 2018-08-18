#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 505;

int M, N, L;
vector<int> club;

vector<pii> adj[MAXN];
int dist[MAXN];
map<pii, int> mp;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> M >> N >> L;
    for(int a = 0; a < L; a++){
        int x;
        cin >> x;
        club.push_back(x);
    }

    for(int a = 1; a <= M; a++){
        int K;
        cin >> K;
        vector<int> V;
        for(int i = 1; i <= K; i++){
            int x;
            cin >> x;
            adj[a + N].push_back(pii(x, 0));
            V.push_back(x);
        }

        for(int i = 0; i < K; i++){
            int u = V[i];
            int v = V[(i + 1) % K];
            if(u > v){
                swap(u, v);
            }

            auto iter = mp.insert({pii(u, v), a + N}).first;
            if(iter->second != a + N){
                adj[iter->second].push_back(pii(a + N, 1));
                adj[a + N].push_back(pii(iter->second, 1));

                mp.erase(iter);
            }
        }
    }

    for(auto au : mp){
        adj[au.second].push_back({0, 1});
        adj[0].push_back({au.second, 1});
    }

    pii best = pii(1e9, -1);
    for(int a = 1; a <= M; a++){
        for(int b = 1; b <= N + M; b++){
            dist[b] = 0x3f3f3f3f;
        }

        int curdist = 0;

        queue<int> q[2];
        dist[a + N] = 0;
        q[0].push(a + N);

        while(!q[0].empty() || !q[1].empty()){
            if(q[0].empty()){
                q[0].swap(q[1]);
                curdist++;
            }

            int fr = q[0].front();
            q[0].pop();

            for(pii p : adj[fr]){
                if(curdist + p.second < dist[p.first]){
                    dist[p.first] = curdist + p.second;
                    q[p.second].push(p.first);
                }
            }
        }

        int sum = 0;
        for(int i : club){
            sum += dist[i];
        }

        best = min(best, pii(sum, a));
    }

    cout << best.first << "\n";
    cout << best.second << "\n";
}
