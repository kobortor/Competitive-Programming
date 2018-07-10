#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5e5 + 5;

int N;
vector<int> adj[MAXN];

void dfs(int pos, int par, int dep, vector<int> &vec){
    for(int i : adj[pos]){
        if(i == par){
            continue;
        }

        dfs(i, pos, dep + 1, vec);
    }

    if((int)adj[pos].size() == 1){
        while(dep >= (int)vec.size()){
            vec.push_back(0);
        }

        vec[dep]++;
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N - 1; a++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    for(int i : adj[1]){
        vector<int> vec;
        dfs(i, 1, 1, vec);

        int cnt = 0;
        for(int a = 0; a < (int)vec.size() || cnt != 0; a++){
            if(a < (int)vec.size()){
                cnt += vec[a];
            }
            if(cnt){
                ans = max(ans, a);
                cnt--;
            }
        }

    }

    cout << ans;
}
