#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5005;

int incoming[MAXN];
vector<int> adj[MAXN];
vector<int> radj[MAXN];
bool vis[MAXN];

int orig_incoming[MAXN];

vector<int> who_wins(vector<int> arezou, vector<int> charge, vector<int> u, vector<int> v){
    int N = arezou.size();
    
    for(int a = 0; a < (int)u.size(); a++){
        adj[u[a]].push_back(v[a]);
        radj[v[a]].push_back(u[a]);
        orig_incoming[u[a]]++;
    }

    vector<int> win(N);

    while(1){
        copy(orig_incoming, orig_incoming + N, incoming);
        fill(vis, vis + N, 0);

        queue<int> q;
        for(int b = 0; b < N; b++){
            if(charge[b]){
                vis[b] = true;
                q.push(b);
            }
        }

        while(!q.empty()){
            int fr = q.front();
            q.pop();

            for(int i : radj[fr]){
                if(vis[i]){
                    continue;
                }
                incoming[i]--;
                if(arezou[i] || incoming[i] == 0){
                    vis[i] = true;
                    q.push(i);
                }
            }
        }

        bool charge_change = false;
        for(int b = 0; b < N; b++){
            if(!charge[b]){
                continue;
            }

            bool good;
            if(arezou[b]){
                good = false;
                for(int i : adj[b]){
                    if(vis[i]) {
                        good = true;
                    }
                }
            } else {
                good = true;
                for(int i : adj[b]){
                    if(!vis[i]) {
                        good = false;
                    }
                }
            }

            if(!good){
                charge[b] = false;
                charge_change = true;
            }
        }

        if(!charge_change){
            for(int b = 0; b < N; b++){
                if(vis[b]){
                    win[b] = true;
                }
            }
            break;
        }
    }

    return win;
}
