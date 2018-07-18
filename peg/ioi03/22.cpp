#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 22;
const int MAXG = 10;
const int MAXT = 24;

struct state {
    char r[2], c[2], tm;
    state(){}
    state(int r0, int c0, int r1, int c1, int _tm){
        r[0] = r0;
        c[0] = c0;
        r[1] = r1;
        c[1] = c1;
        tm = _tm;
    }
    int hashcode(){
        return r[0] + MAXN * (c[0] + MAXN * (r[1] + MAXN * (c[1] + MAXN * (tm))));
    }
};
char dirch[] = {'N', 'S', 'E', 'W'}; 
pii getdir(char ch){
    switch(ch){
        case 'N': return pii(-1, 0);
        case 'S': return pii(+1, 0);
        case 'E': return pii(0, +1);
        case 'W': return pii(0, -1);
        default: assert(false);
    }
}

int R[2], C[2];
char grid[2][MAXN][MAXN];
int G[2];
pii guard[2][MAXG][MAXT];
pii init[2];
int dist[MAXN * MAXN * MAXN * MAXN * MAXT];
state prv[MAXN * MAXN * MAXN * MAXN * MAXT];
char prvc[MAXN * MAXN * MAXN * MAXN * MAXT];

bool in_grid(int r, int c, int id){
    return 1 <= r && r <= R[id] && 1 <= c && c <= C[id];
}

void print_ans(state curst){
    string path;
    while(true){
        if(dist[curst.hashcode()] == 0){
            break;
        }
        
        state prvst = prv[curst.hashcode()];
        path += prvc[curst.hashcode()];

        curst = prvst;
    }

    reverse(allof(path));
    cout << path.size() << "\n";
    for(char c : path){
        cout << c << "\n";
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for(int id = 0; id < 2; id++){
        cin >> R[id] >> C[id];
        for(int a = 1; a <= R[id]; a++){
            cin >> (grid[id][a] + 1);
            for(int b = 1; b <= C[id]; b++){
                if(grid[id][a][b] == 'X'){
                    init[id] = pii(a, b);
                }
            }
        }

        cin >> G[id];
        for(int a = 0; a < G[id]; a++){
            pii start;
            char ch;
            int len;
            cin >> start.first >> start.second >> len >> ch;

            pii dir = getdir(ch);
            int guard_len = 2 * len - 2;

            for(int b = 0; b < len; b++){
                guard[id][a][b] = pii(start.first + dir.first * b, start.second + dir.second * b);
                guard[id][a][2 * len - 2 - b] = guard[id][a][b];
            }

            for(int b = guard_len; b < MAXT; b++){
                guard[id][a][b] = guard[id][a][b - guard_len];
            }
        }
    }

    memset(dist, -1, sizeof dist);

    queue<pair<int, state>> q;
    q.push({0, {init[0].first, init[0].second, init[1].first, init[1].second, 0}});
    dist[state(init[0].first, init[0].second, init[1].first, init[1].second, 0).hashcode()] = 0;

    while(!q.empty()){
        int curdist;
        state st;
        tie(curdist, st) = q.front();
        q.pop();
        
        if(!in_grid(st.r[0], st.c[0], 0) && !in_grid(st.r[1], st.c[1], 1)){
            print_ans(st);
            return 0;
        }


        for(char ch : dirch){
            pii dir = getdir(ch);
            state nxtst;
            nxtst.tm = (st.tm + 1) % MAXT;
            bool good = true;

            for(int id = 0; id < 2; id++){
                if(in_grid(st.r[id], st.c[id], id)){
                    int nr = st.r[id] + dir.first;
                    int nc = st.c[id] + dir.second;
                    if(in_grid(nr, nc, id)){
                        if(grid[id][nr][nc] == '#'){
                            nr = st.r[id];
                            nc = st.c[id];
                        }

                        for(int a = 0; a < G[id]; a++){
                            pii posid = guard[id][a][st.tm];
                            pii pos1 = guard[id][a][nxtst.tm];

                            good &= pos1 != pii(nr, nc); //cannot end on same place
                            good &= posid != pii(nr, nc) || pos1 != pii(st.r[id], st.c[id]); //cannot swap place
                        }
                    }

                    nxtst.r[id] = nr;
                    nxtst.c[id] = nc;
                } else {
                    nxtst.r[id] = st.r[id];
                    nxtst.c[id] = st.c[id];
                }
            }

            if(good && dist[nxtst.hashcode()] == -1){
                dist[nxtst.hashcode()] = curdist + 1;
                prv[nxtst.hashcode()] = st;
                prvc[nxtst.hashcode()] = ch;
                q.push({curdist + 1, nxtst});
            }
        }
    }

    cout << -1;
}
