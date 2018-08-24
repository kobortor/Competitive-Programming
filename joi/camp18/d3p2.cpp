#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;
const int SQ = 320;

int N, M, Q;

bool vis[MAXN];
int dist[MAXN];
vector<pii> best[MAXN];
vector<int> adj[MAXN];
vector<int> rev[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> Q;
    for(int a = 1; a <= M; a++){
        int s, e;
        cin >> s >> e;
        adj[s].push_back(e);
        rev[e].push_back(s);
    }

    for(int a = 1; a <= N; a++){
        vector<int> seen;
        seen.push_back(a);
        vis[a] = true;

        for(int i : rev[a]){
            for(pii p : best[i]){
                if(!vis[p.second]){
                    vis[p.second] = true;
                    seen.push_back(p.second);
                }
                dist[p.second] = max(dist[p.second], p.first + 1);
            }
        }

        for(int i : seen){
            vis[i] = false;
            best[a].push_back(pii(dist[i], i));
            dist[i] = 0;
        }
        sort(allof(best[a]), greater<pii>());
        while((int)best[a].size() > SQ){
            best[a].pop_back();
        }
    }

    while(Q--){
        int T, Y;
        cin >> T >> Y;
        vector<int> busy;
        for(int a = 0; a < Y; a++){
            int x;
            cin >> x;
            vis[x] = true;
            busy.push_back(x);
        }

        if(Y < SQ){
            bool seen = false;
            for(pii p : best[T]){
                if(!vis[p.second]){
                    seen = true;
                    cout << p.first << "\n";
                    break;
                }
            }
            if(!seen){
                cout << "-1\n";
            }
        } else {
            memset(dist, 0xaf, sizeof dist);

            int ans = -1;
            dist[T] = 0;
            for(int a = T; a >= 1; a--){
                for(int i : adj[a]){
                    dist[a] = max(dist[a], dist[i] + 1);
                }

                if(!vis[a]){
                    ans = max(ans, dist[a]);
                }
            }
            cout << ans << "\n";
        }

        for(int x : busy){
            vis[x] = false;
        }
    }
}
