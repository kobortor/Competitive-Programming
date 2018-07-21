#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 805;

int N, S;
char orig[MAXN][MAXN];
char grid[MAXN][MAXN];
int dist[MAXN][MAXN];

bool ingrid(int r, int c){
    return 0 <= r && r < N && 0 <= c && c < N;
}

pii dir[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

//standard queues are too slow
struct myqueue {
    int fr = 0;
    vector<pii> data;

    void push(const pii &p){
        data.emplace_back(p);
    }

    pii front(){
        return data[fr];
    }

    bool empty(){
        return fr == (int)data.size();
    }

    void pop(){
        fr++;
    }
}; 

bool good(int wait){
    memcpy(grid, orig, sizeof orig);
    memset(dist, 0x3f, sizeof dist);

    myqueue bees, bear;
    for(int a = 0; a < N; a++){
        for(int b = 0; b < N; b++){
            if(grid[a][b] == 'M'){
                bear.push({a, b});
                dist[a][b] = 0;
            } else if (grid[a][b] == 'H'){
                grid[a][b] = 'T';
                bees.push({a, b});
            }
        }
    }

    while(wait--){
        myqueue tmp;
        while(!bees.empty()){
            int r, c;
            tie(r, c) = bees.front();
            bees.pop();

            for(pii p : dir){
                if(!ingrid(r + p.first, c + p.second) || grid[r + p.first][c + p.second] == 'T' || grid[r + p.first][c + p.second] == 'D'){
                    continue;
                }

                grid[r + p.first][c + p.second] = 'T';
                tmp.push({r + p.first, c + p.second});
            }
        }

        bees.data.swap(tmp.data);
        swap(bees.fr, tmp.fr);
    }

    for(int step = 1; !bear.empty(); step++){
        myqueue tmp;

        while(!bear.empty()){
            int r, c;
            tie(r, c) = bear.front();

            if(grid[r][c] == 'D'){
                return true;
            }

            if(dist[r][c] >= step * S){
                break;
            }

            bear.pop();

            if(grid[r][c] == 'T'){
                continue;
            }

            for(pii p : dir){
                if(!ingrid(r + p.first, c + p.second) || grid[r + p.first][c + p.second] == 'T'){
                    continue;
                }

                if(dist[r][c] + 1 < dist[r + p.first][c + p.second]){
                    dist[r + p.first][c + p.second] = dist[r][c] + 1;
                    bear.push({r + p.first, c + p.second});
                }
            }
        }

        while(!bees.empty()){
            int r, c;
            tie(r, c) = bees.front();
            bees.pop();

            for(pii p : dir){
                if(!ingrid(r + p.first, c + p.second) || grid[r + p.first][c + p.second] == 'T' || grid[r + p.first][c + p.second] == 'D'){
                    continue;
                }

                grid[r + p.first][c + p.second] = 'T';
                tmp.push({r + p.first, c + p.second});
            }
        }

        bees.data.swap(tmp.data);
        swap(bees.fr, tmp.fr);
    }

    return false;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> S;

    for(int a = 0; a < N; a++){
        cin >> orig[a];
    }

    int lo = 0, hi = MAXN * MAXN;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(good(mid)){
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << lo - 1;
}
