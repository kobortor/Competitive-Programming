#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;

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

    int bestid = 0;
    for(int a = 1; a <= N; a++){
        if((int)adj[a].size() >= 3){
            if(bestid == 0){
                bestid = a;
            } else {
                cout << "No\n";
                return 0;
            }
        }
    }

    if(bestid == 0){
        bestid = 1;
    }

    vector<int> paths;
    for(int a = 1; a <= N; a++){
        if(a != bestid && (int)adj[a].size() == 1) {
            paths.push_back(a);
        }
    }

    cout << "Yes\n";
    cout << paths.size() << "\n";
    for(int i : paths){
        cout << i << " " << bestid << "\n";
    }
}
