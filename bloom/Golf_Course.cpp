#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> adj[10];

void edge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int cur[10], nxt[10];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    edge(1, 6);
    edge(4, 9);

    edge(3, 4);
    edge(6, 7);

    edge(1, 8);
    edge(2, 9);
    edge(4, 0);

    edge(2, 7);
    edge(3, 8);
    edge(6, 0);

    int N;
    cin >> N;

    cur[1] = 1;
    for(int a = 0; a < N; a++){
        for(int i = 0; i < 10; i++){
            for(int j : adj[i]){
                nxt[j] += cur[i];
            }
        }
        copy(nxt, nxt + 10, cur);
        fill(nxt, nxt + 10, 0);
    }

    cout << cur[9];
}
