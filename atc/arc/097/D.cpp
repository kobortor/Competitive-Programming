#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;

vector<int> adj[MAXN];
int edges[MAXN];
char col[MAXN];
bool removed[MAXN];
int remain;

//if we changed the parity of (# times going into x), how does the value change?
int fixval(int x){
    return (edges[x] % 2 == 0 && col[x] == 'W') || (edges[x] % 2 == 1 && col[x] == 'B') ? 1 : -1;
}

int reduce = 0;

pii bestup[MAXN][2];
pii bestdown[MAXN][2];

void insert_pii(pii arr[2], pii to_ins){
    if(to_ins > arr[0]){
        arr[1] = arr[0];
        arr[0] = to_ins;
    } else if (to_ins > arr[1]){
        arr[1] = to_ins;
    }
}

void dfs(int pos, int par){
    bestup[pos][0] = pii(-1e9, -1);
    bestup[pos][1] = pii(-1e9, -2);

    bestdown[pos][0] = pii(-1e9, -1);
    bestdown[pos][1] = pii(-1e9, -2);

    for(int i : adj[pos]){
        if(i == par || removed[i]){
            continue;
        }
        dfs(i, pos);

        insert_pii(bestup[pos], pii(bestup[i][0].first + 1 + fixval(pos), i));
        insert_pii(bestdown[pos], pii(bestdown[i][0].first + 1 + fixval(pos), i));
    }
    
    reduce = max(reduce, bestup[pos][0].first - fixval(pos));
    reduce = max(reduce, bestdown[pos][0].first);

    if(bestup[pos][0].second == bestdown[pos][0].second){
        reduce = max(reduce, bestup[pos][0].first + bestdown[pos][1].first - fixval(pos));
        reduce = max(reduce, bestup[pos][1].first + bestdown[pos][0].first - fixval(pos));
    } else {
        reduce = max(reduce, bestup[pos][0].first + bestdown[pos][0].first - fixval(pos));
    }

    insert_pii(bestup[pos], pii(fixval(pos), pos));
    insert_pii(bestdown[pos], pii(0, pos));
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    remain = N;
    for(int a = 1; a <= N - 1; a++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        edges[u]++;
        edges[v]++;
    }

    cin >> (col + 1);

    queue<int> q;
    for(int a = 1; a <= N; a++){
        if(edges[a] == 1 && col[a] == 'B'){
            q.push(a);
        }
    }

    while(!q.empty()){
        int fr = q.front();
        q.pop();

        remain--;
        removed[fr] = true;

        for(int i : adj[fr]){
            edges[i]--;
            if(edges[i] == 1 && col[i] == 'B'){
                q.push(i);
            }
        }
    }

    if(remain == 0){
        cout << 0;
        return 0;
    }

    int start = -1;
    int ans = 2 * (remain - 1);
    for(int a = 1; a <= N; a++){
        if(!removed[a]){
            start = a;
            ans += (fixval(a) == 1);
        }
    }

    if(start == -1){
        cout << 0;
    } else if (remain == 1){
        cout << (col[start] == 'W');
    } else if (remain == 2){
        cout << 2;
    } else {
        dfs(start, -1);
        cout << ans - reduce;
    }
}
