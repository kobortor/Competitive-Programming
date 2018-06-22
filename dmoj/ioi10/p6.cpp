#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 6;

typedef pair<int, int> pii;

int N;
int *fans;
vector<int> adj[MAXN];
int below[MAXN];

int tot = 0;
pii best = pii(INT_MAX, -1);

void dfs(int pos, int par){
    below[pos] = fans[pos];

    int most = 0;
    for(int i : adj[pos]){
        if(i == par) {
            continue;
        }

        dfs(i, pos);

        below[pos] += below[i];

        most = max(most, below[i]);
    }

    most = max(most, tot - below[pos]);

    best = min(best, pii(most, pos));
}

int LocateCentre(int _N, int pp[], int S[], int D[]) {
    N = _N;
    fans = pp;

    for(int a = 0; a < N; a++){
        tot += fans[a];
    }

    for(int a = 0; a < N - 1; a++){
        adj[S[a]].push_back(D[a]);
        adj[D[a]].push_back(S[a]);
    }

    dfs(0, -1);

    return best.second;
}
