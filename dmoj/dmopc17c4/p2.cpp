#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int N, Q;

int par[MAXN];
vector<int> adj[MAXN];
int dep[MAXN];

void dfs(int pos){
    for(int i : adj[pos]){
        if(i != par[pos]){
            dep[i] = dep[pos] + 1;
            par[i] = pos;
            dfs(i);
        }
    }
}

int val[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> Q;

    for(int a = 1; a <= N; a++){
        cin >> val[a];
    }

    for(int a = 0; a < N - 1; a++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);

    while(Q--){
        int tp, x, y;
        cin >> tp >> x >> y;

        vector<int> vals;
        while(x != y){
            if(dep[x] < dep[y]){
                swap(x, y);
            }
            vals.push_back(val[x]);
            x = par[x];
        }
        vals.push_back(val[x]);

        if(tp == 1){
            ll sum = 0;
            for(int i : vals){
                sum += i;
            }
            cout << (ll)round((double)sum / vals.size()) << "\n";
        } else if (tp == 2){
            sort(allof(vals));
            if(vals.size() & 1){
                cout << vals[vals.size() / 2] << "\n";
            } else {
                cout << (vals[vals.size() / 2 - 1] + vals[vals.size() / 2] + 1) / 2 << "\n";
            }
        } else {
            sort(allof(vals));
            pii best = pii(0, 0);
            for(int a = 0; a < (int)vals.size();){
                int b = a + 1;
                while(b < (int)vals.size() && vals[a] == vals[b]){
                    b++;
                }
                best = max(best, pii(b - a, -vals[a]));
                a = b;
            }
            cout << -best.second << "\n";
        }
    }
}
