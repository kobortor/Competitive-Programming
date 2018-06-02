#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 22;

int N, M;

int ht[MAXN][MAXN];
int filled[MAXN][MAXN];
bool vis[MAXN][MAXN];

bool good(int r, int c){
    return 0 <= r && r < N && 0 <= c && c < M;
}

priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
int ans = 0;

void fill_to(int r, int c, int val){
    if(r < 0 || r >= N || c < 0 || c >= M){
        return;
    }

    if(vis[r][c]){
        return;
    }

    ans += max(0, val - ht[r][c]);
    vis[r][c] = true;

    pq.push({ht[r][c], {r, c}});

    if(ht[r][c] > val){
        return;
    }

    fill_to(r - 1, c, val);
    fill_to(r + 1, c, val);
    fill_to(r, c - 1, val);
    fill_to(r, c + 1, val);
}

void testcase(){
    cin >> N >> M;

    ans = 0;
    memset(filled, 0, sizeof filled);

    for(int a = 0; a < N; a++){
        for(int b = 0; b < M; b++){
            cin >> ht[a][b];
            filled[a][b] = 0;
            vis[a][b] = (a == 0 || a == N - 1 || b == 0 || b == M - 1);
            if(vis[a][b]){
                pq.push({ht[a][b], {a, b}});
            }
        }
    }

    while(!pq.empty()){
        pair<int, pii> top = pq.top();
        pq.pop();

        int r = top.second.first;
        int c = top.second.second;

        fill_to(r - 1, c, top.first);
        fill_to(r + 1, c, top.first);
        fill_to(r, c - 1, top.first);
        fill_to(r, c + 1, top.first);
    }
    cout << ans << "\n";
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for(int T = 1; T <= 5; T++){
        testcase();
    }
}
