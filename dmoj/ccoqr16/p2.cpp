#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;

map<int, int> id[MAXN];
int nxt[MAXN];

vector<bool> vis[MAXN];
vector<int> adj[MAXN];

int best[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        int K;
        cin >> K;
        for(int b = 0; b < K; b++){
            vis[a].push_back(0);
            int x;
            cin >> x;
            adj[a].push_back(x);
            id[a][x] = (b + K - 1) % K;
        }
    }

    for(int a = 1; a <= N; a++){
        for(int b = 0; b < (int)adj[a].size(); b++){
            if(!vis[a][b]){
                pii cur = pii(a, b);

                int cnt = 0;
                map<int, vector<int>> mp;
                do {
                    vis[cur.first][cur.second] = true;
                    mp[cur.first].push_back(cnt++);

                    int nxtid = adj[cur.first][cur.second];
                    int nxtdir = id[nxtid][cur.first];
                    cur = pii(nxtid, nxtdir);
                } while (cur != pii(a, b));

                for(auto &au : mp){
                    int idx = au.first;
                    vector<int> &vec = au.second;
                    best[idx] = max(best[idx], cnt - (vec.back() - vec[0]));
                    for(int i = 1; i < (int)vec.size(); i++){
                        best[idx] = max(best[idx], vec[i] - vec[i-1]);
                    }
                }
            }
        }
    }

    int Q;
    cin >> Q;
    while(Q--){
        int x;
        cin >> x;
        cout << best[x] << "\n";
    }
}
