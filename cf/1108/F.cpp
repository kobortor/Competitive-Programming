#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N, M;
int dsu[MAXN];
pair<int, pii> edges[MAXN];

int find(int x) { return dsu[x] == x ? x : dsu[x] = find(dsu[x]); }

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    for(int a = 1; a <= N; a++) dsu[a] = a;

    for(int a = 0; a < M; a++){
        cin >> edges[a].second.first >> edges[a].second.second >> edges[a].first;
    }

    sort(edges, edges + M);
    int ans = 0;

    for(int a = 0; a < M; a++){
        int b = a;
        while(b + 1 < M && edges[b + 1].first == edges[a].first){
            b++;
        }

        for(int i = a; i <= b; i++){
            if(find(edges[i].second.first) != find(edges[i].second.second)){
                ans++;
            }
        }

        for(int i = a; i <= b; i++){
            int u = find(edges[i].second.first);
            int v = find(edges[i].second.second);

            if(u != v) dsu[u] = v;
        }

        a = b;
    }

    ans -= N - 1;
    cout << ans;
}
