#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5e3 + 5;

int N, M;
ll best[MAXN][2];
vector<pii> adj[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(best, 0x3f, sizeof best);

    cin >> N >> M;

    while(M--){
        int Ai, Bi, Wi;
        cin >> Ai >> Bi >> Wi;
        adj[Ai].push_back(pii(Bi, Wi));
        adj[Bi].push_back(pii(Ai, Wi));
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    best[1][0] = 0;
    pq.push(pii(0, 1));
    while(!pq.empty()){
        pii top = pq.top();
        pq.pop();
        for(pii p : adj[top.second]){
            int cost = top.first + p.second;
            if(cost < best[p.first][0]){
                best[p.first][1] = best[p.first][0];
                best[p.first][0] = cost;

                pq.push(pii(cost, p.first));
            } else if (cost != best[p.first][0] && cost < best[p.first][1]){
                best[p.first][1] = cost;
                
                pq.push(pii(cost, p.first));
            }
        }
    }
    cout << best[N][1] << "\n";
}
