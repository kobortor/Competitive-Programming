#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int gcd(int x, int y){
    while(x % y){
        x %= y;
        swap(x, y);
    }
    return y;
}

int N;
vector<int> adj[MAXN];
int val[MAXN];

ll ans[MAXN];
unordered_map<int, int> freq[MAXN];

void dfs(int pos, int par){
    freq[pos][val[pos]] = 1;
    ans[val[pos]]++;

    for(int i : adj[pos]){
        if(i == par){
            continue;
        }

        dfs(i, pos);

        for(const pii &p1 : freq[i]){
            int newv = gcd(p1.first, val[pos]);

            for(const pii &p2 : freq[pos]){
                int g = gcd(newv, p2.first);

                ans[g] += (ll)p1.second * p2.second;
            }
        }

        for(const pii &p1 : freq[i]){
            int newv = gcd(p1.first, val[pos]);
            freq[pos][newv] += p1.second;
        }
        freq[i].clear();
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    
    for(int a = 1; a <= N; a++){
        cin >> val[a];
    }

    for(int a = 1; a <= N - 1; a++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    for(int a = 1; a < MAXN; a++){
        if(ans[a] != 0){
            cout << a << " " << ans[a] << "\n";
        }
    }
}
