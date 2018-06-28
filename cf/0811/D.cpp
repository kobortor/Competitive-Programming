#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/*
Very bad problem. Too many cases to code and debug.
*/

const int MAXN = 105;

int N, M;

int fr, fc;

char grid[MAXN][MAXN];

pii getmv(char mv){
    cout << mv << endl;
    pii ret;
    cin >> ret.first >> ret.second;
    return ret;
}

int best[MAXN][MAXN];
char prvmv[MAXN][MAXN];
pii prvpos[MAXN][MAXN];

void dfs(char U, char D, char L, char R) {
    vector<pii> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<char> prints = {U, D, L, R};

    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= M; b++){
            best[a][b] = 0x3f3f3f3f;
        }
    }
    best[1][1] = 0;
    queue<pii> q;
    q.push({1, 1});
    while(!q.empty()){
        pii p = q.front();
        for(int a = 0; a < 4; a++){
            int pr = p.first + moves[a].first;
            int pc = p.second + moves[a].second;
            if(grid[pr][pc] == '*') {
                continue;
            }

            if(best[p.first][p.second] + 1 < best[pr][pc]) {
                best[pr][pc] = best[p.first][p.second] + 1;
                prvmv[pr][pc] = prints[a];
                prvpos[pr][pc] = p;

                q.push({pr, pc});
            }
        }
    }
    vector<char> out;
    pii p = {fr, fc};
    while(p != pii(1,1)){
        out.push_back(prvmv[p.first][p.second]);
        p = prvpos[p.first][p.second];
    }
    reverse(out.begin(), out.end());
    for(char c : out){
        getmv(c);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> N >> M;

    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= M; b++){
            cin >> grid[a][b];
            if(grid[a][b] == 'F'){
                fr = a, fc = b;
            }
        }
    }

    if(fr == 1 && fc == 1){ //if we start at beginning
        return 0;
    }

    if(fr == 1){
        bool is_clear = true;
        for(int a = 1; a < fc; a++){
            if(grid[1][a] == '*'){
                is_clear = false;
            }
        }
        if(is_clear){
            //just move randomly
            for(int a = 0; a < M; a++){
                if(getmv('L') == pii(fr, fc)){
                    return 0;
                }
            }
            for(int a = 0; a < M; a++){
                if(getmv('R') == pii(fr, fc)){
                    return 0;
                }
            }
            return 0;
        }
    }
    if (fc == 1){
        bool is_clear = true;
        for(int a = 1; a < fr; a++){
            if(grid[a][1] == '*'){
                is_clear = false;
            }
        }
        if(is_clear){
            //just move randomly
            for(int a = 0; a < N; a++){
                if(getmv('U') == pii(fr, fc)){
                    return 0;
                }
            }
            for(int a = 0; a < N; a++){
                if(getmv('D') == pii(fr, fc)){
                    return 0;
                }
            }
            return 0;
        }
    }
    if (grid[1][2] == '.') {
        bool flipC = getmv('R') == pii(1, 1);
        if(!flipC){
            getmv('L');
        }
        bool flipR = false;;

        int cc = 1;
        while(1) {
            if(grid[2][cc] == '.') {
                flipR = getmv('D') == pii(1, cc);
                if(!flipR){
                    getmv('U');
                }
            }
            cc++;
            getmv(flipC ? 'L' : 'R');
        }
        while(cc > 1){
            getmv(flipC ? 'R' : 'L');
            cc--;
        }
        dfs(flipR ? 'D' : 'U',
            flipR ? 'U' : 'D',
            flipC ? 'R' : 'L',
            flipC ? 'L' : 'R');
    } else if (grid[2][1] == '.') {
        bool flipR = getmv('D') == pii(1, 1);
        if(!flipR){
            getmv('U');
        }
        bool flipC = false;

        int rr = 1;
        while(1) {
            if(grid[rr][2] == '.') {
                flipC = getmv('R') == pii(rr, 1);
                if(!flipC){
                    getmv('L');
                }
            }
            rr++;
            getmv(flipR ? 'U' : 'D');
        }
        while(rr > 1){
            getmv(flipR ? 'D' : 'U');
            rr--;
        }
        dfs(flipR ? 'D' : 'U',
            flipR ? 'U' : 'D',
            flipC ? 'R' : 'L',
            flipC ? 'L' : 'R');
    }
}