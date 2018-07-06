#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
int color[MAXN];
int change[MAXN];
vector<int> adj[MAXN];

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

    for(int a = 1; a <= N; a++){
        cin >> color[a];
    }

    int tot_change = 0;
    for(int a = 1; a <= N; a++){
        for(int i : adj[a]){
            if(a < i && color[a] != color[i]){
                tot_change++;
                change[a]++;
                change[i]++;
            }
        }
    }

    int ans = -1;
    for(int i = 1; i <= N; i++){
        if(change[i] == tot_change){
            ans = i;
            break;
        }
    }

    if(ans == -1){
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << ans << "\n";
    }
}
