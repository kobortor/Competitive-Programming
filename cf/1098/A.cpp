#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;

ll ans;
vector<int> adj[MAXN];
int val[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 2; a <= N; a++){
        int x;
        cin >> x;
        adj[x].push_back(a);
    }

    for(int a = 1; a <= N; a++){
        cin >> val[a];
    }

    ans = val[1];
    for(int a = 1; a <= N; a++){
        if(val[a] == -1) continue;
        for(int i : adj[a]){
            if(adj[i].empty()) continue;

            int best = 1e9;
            for(int j : adj[i]){
                if(val[j] < val[a]){
                    cout << -1;
                    return 0;
                }
                best = min(best, val[j]);
            }

            ans += best - val[a];
            for(int j : adj[i]){
                ans += val[j] - best;
            }
        }
    }

    cout << ans;
}
