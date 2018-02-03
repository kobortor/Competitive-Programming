#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;
const int MAXM = 5005;

ll N, M, K;
ll S, T;

ll A[MAXM];
ll B[MAXM];
ll C[MAXM];
ll D[MAXM];

bool vis[MAXN];
vector<int> adj[MAXN];

void dfs(int pos){
    vis[pos] = true;
    for(int i : adj[pos]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

bool check(int val){
    for(int a = 1; a <= N; a++){
        adj[a].clear();
        vis[a] = false;
    }

    for(int a = 0; a < M; a++){
        if(C[a] <= val && val <= D[a]){
            adj[A[a]].push_back(B[a]);
        }
    }

    dfs(S);
    return vis[T];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> K;
    cin >> S >> T;

    vector<int> uniq;
    uniq.push_back(0);
    uniq.push_back(K + 1);

    for(int a = 0; a < M; a++){
        cin >> A[a];
        cin >> B[a];
        cin >> C[a];
        cin >> D[a];

        uniq.push_back(C[a]);
        uniq.push_back(D[a] + 1);
    }
    sort(allof(uniq));
    uniq.erase(unique(allof(uniq)), uniq.end());

    int ans = 0;
    for(int a = 0; a + 1 < (int) uniq.size(); a++){
        if(check(uniq[a])){
            ans += uniq[a + 1] - uniq[a];
        }
    }
    cout << ans;
}
