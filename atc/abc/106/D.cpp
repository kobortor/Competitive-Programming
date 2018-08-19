#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 505;

int N, M, Q;

int tot[MAXN];
int trains[MAXN][MAXN];
vector<pii> queries[MAXN];
int out[100005];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> Q;

    for(int a = 1; a <= M; a++){
        int l, r;
        cin >> l >> r;
        trains[l][r]++;
    }

    for(int a = 1; a <= Q; a++){
        int p, q;
        cin >> p >> q;
        queries[p].push_back({q, a});
    }

    for(int a = N; a >= 1; a--){
        for(int b = a, accum = 0; b <= N; b++){
            accum += trains[a][b];
            tot[b] += accum;
        }

        for(pii p : queries[a]){
            out[p.second] = tot[p.first];
        }
    }

    for(int a = 1; a <= Q; a++){
        cout << out[a] << "\n";
    }
}
