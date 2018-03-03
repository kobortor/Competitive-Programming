#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 205;

int N, M, C, K;

pii stu[MAXN];
pii bus[MAXN];
int line[MAXN]; //which line the bus stop belongs to

int head[MAXN];
struct edge {
    int nxt, cap, prv;
    edge(int n, int c, int p){
        nxt = n;
        cap = c;
        prv = p;
    }
};
vector<edge> edges;

void reset(){
    memset(head, -1, sizeof head);
    edges.clear();
}

void add_edge(int u, int v, int c){
    edges.emplace_back(v, c, head[u]); head[u] = edges.size() - 1;
    edges.emplace_back(u, 0, head[v]); head[v] = edges.size() - 1;
}

int sqdist(pii a, pii b){
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

void build_graph(int lim){
    reset();
    for(int a = 1; a <= N; a++){
        add_edge(0, a, 1);
    }
    for(int a = 1; a <= K; a++){
        add_edge(N + a, MAXN - 1, C);
    }
    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= M; b++){
            int dist = sqdist(stu[a], bus[b]);
            if(dist <= lim){
                add_edge(a, N + line[b], 1);
            }
        }
    }
}

int par[MAXN];
bool bfs(){
    memset(par, -1, sizeof par);
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int fr = q.front();
        q.pop();

        int id = head[fr];
        while(id != -1){
            if(edges[id].cap && par[edges[id].nxt] == -1){
                par[edges[id].nxt] = id ^ 1;
                q.push(edges[id].nxt);
            }
            id = edges[id].prv;
        }
    }
    if(par[MAXN - 1] == -1){
        return false;
    }
    int id = MAXN - 1;
    while(id != 0){
        int pth = par[id];
        edges[pth].cap++;
        edges[pth ^ 1].cap--;

        id = edges[pth].nxt;
    }
    return true;
}

int flow(){
    int ans = 0;
    while(bfs()){
        ans++;
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> C >> K;
    if(C * K < N){
        cout << -1;
        return 0;
    }
    for(int a = 1; a <= N; a++){
        cin >> stu[a].first;
        cin >> stu[a].second;
    }
    for(int a = 1; a <= M; a++){
        cin >> bus[a].first;
        cin >> bus[a].second;
    }
    for(int a = 1; a <= K; a++){
        int Ki;
        cin >> Ki;
        while(Ki--){
            int st;
            cin >> st;
            line[st] = a;
        }
    }
    int lo = 1, hi = 2 * 2005 * 2005;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        build_graph(mid);
        if(flow() == N){
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    build_graph(lo);
    flow();
    cout << lo << "\n";
    for(int a = 1; a <= N; a++){
        int id = head[a];
        while(id != -1){
            if(N + 1 <= edges[id].nxt && edges[id].nxt <= N + K){
                if(edges[id].cap == 0){
                    int lineid = edges[id].nxt - N;
                    int best = -1;

                    for(int c = 1; c <= M; c++){
                        if(line[c] == lineid){
                            if(sqdist(stu[a], bus[c]) <= lo){
                                best = c;
                                break;
                            }
                        }
                    }
                    cout << best << "\n";
                }
            }
            id = edges[id].prv;
        }
    }
    
}
