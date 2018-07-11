#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1505;

int N, M, Q;

int cnt = 1;
int disc[MAXN * MAXN], low[MAXN * MAXN];
string grid[MAXN];

int getid(int r, int c){ 
    return r * MAXN + c;
}

pii revid(int id){
    return pii(id / MAXN, id % MAXN);
}

bool vis[MAXN * MAXN];
int adj[MAXN * MAXN][4];

void fill_dfs(int pos){
    int r, c;
    tie(r, c) = revid(pos);
    if(grid[r][c] == 'B'){
        return;
    }

    vis[pos] = true;
 
    for(int i : adj[pos]){
        if(i == -1){
            continue;
        }
        if(!vis[i]){
            fill_dfs(i);
        }
    }
}

int scccnt = 1;
set<int> scc[MAXN * MAXN];
stack<int> stk;

void tarjan(int pos){
    disc[pos] = low[pos] = cnt++;
    stk.push(pos);

    for(int i : adj[pos]){
        if(i == -1){
            continue;
        }

        if(!disc[i]){
            tarjan(i);
            low[pos] = min(low[pos], low[i]);

            if(low[i] == disc[pos]){
                while(stk.top() != i){
                    scc[stk.top()].insert(scccnt);
                    stk.pop();
                }

                scc[stk.top()].insert(scccnt);
                stk.pop();

                scc[pos].insert(scccnt);

                scccnt++;
            }
        } else {
            low[pos] = min(low[pos], disc[i]);
        }
    }
}

/*
0 - UP
1 - DOWN
2 - LEFT
3 - RIGHT

dir ^ 1 gets the opposite direction
*/
int getid2(int r, int c, int dir){
    return r * MAXN * 4 + c * 4 + dir;
}

int getid2(int posid, int dir){
    return posid * 4 + dir;
}

pair<pii, int> revid2(int pos){
    return {{pos / (MAXN * 4), pos % (MAXN * 4) / 4}, pos % 4};
}

bool vis2[MAXN * MAXN * 4];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    freopen("pushabox.in", "r", stdin);
    freopen("pushabox.out", "w", stdout);

    cin >> N >> M >> Q;
    for(int a = 0; a < N; a++){
        cin >> grid[a];
    }

    memset(adj, -1, sizeof adj);

    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            int id = getid(r, c);
            if(grid[r][c] == '#'){
                continue;
            }
            if(r != 0 && grid[r - 1][c] != '#'){
                adj[id][0] = getid(r - 1, c);
            }
            if(r != N - 1 && grid[r + 1][c] != '#'){
                adj[id][1] = getid(r + 1, c);
            }
            if(c != 0 && grid[r][c - 1] != '#'){
                adj[id][2] = getid(r, c - 1);
            }
            if(c != M - 1 && grid[r][c + 1] != '#'){
                adj[id][3] = getid(r, c + 1);
            }
        }
    }

    pii posb;
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            if(grid[r][c] == 'A'){
                fill_dfs(getid(r, c));
            }

            if(grid[r][c] == 'B'){
                posb = pii(r, c);
            }

            if(grid[r][c] != '#' && !disc[getid(r, c)]){
                tarjan(getid(r, c));

                stk.pop();
            }
        }
    }

    //<pos, position of cow (relative to box)>
    queue<int> q;
    for(int a = 0; a < 4; a++){
        if(adj[getid(posb.first, posb.second)][a] != -1 &&
            vis[adj[getid(posb.first, posb.second)][a]]){
            q.push(getid2(posb.first, posb.second, a));
            vis2[getid2(posb.first, posb.second, a)] = true;
        }
    }

    while(!q.empty()){
        pii pos;
        int dir; //position of cow relative to box
        tie(pos, dir) = revid2(q.front());
        q.pop();

        int r, c;
        tie(r, c) = pos;

        int boxpos = getid(r, c);

        //push in direction opposite to cow
        if(adj[boxpos][dir ^ 1] != -1 && !vis2[getid2(adj[boxpos][dir ^ 1], dir)]){
            vis2[getid2(adj[boxpos][dir ^ 1], dir)] = true;
            q.push(getid2(adj[boxpos][dir ^ 1], dir));
        }

        int cowpos = adj[boxpos][dir];

        for(int nxtdir = 0; nxtdir < 4; nxtdir++){
            int nxtpos = adj[boxpos][nxtdir];
            if(nxtpos == cowpos || nxtpos == -1 || vis2[getid2(boxpos, nxtdir)]){
                continue;
            }

            bool good = false;
            for(int i : scc[cowpos]){
                if(scc[nxtpos].count(i)){
                    good = true;
                    break;
                }
            }

            if(good){
                vis2[getid2(boxpos, nxtdir)] = true;
                q.push(getid2(boxpos, nxtdir));
            }
        }
    }

    while(Q--){
        int r, c;
        cin >> r >> c;

        r--;
        c--;

        bool good = (grid[r][c] == 'B');
        for(int dir = 0; dir < 4; dir++){
            good |= vis2[getid2(r, c, dir)];
        }

        if(good){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
