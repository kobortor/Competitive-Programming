#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, M;

vector<int> avail[MAXN];
int dsu[MAXN];

int find(int x){
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    for(int a = 1; a <= N; a++){
        dsu[a] = a;
        int x;
        cin >> x;
        avail[a].push_back(x);
    }

    while(M--){
        int u, v;
        cin >> u >> v;
        int fu = find(u);
        int fv = find(v);

        if(fu != fv){
            if(avail[fv].size() > avail[fu].size()){
                swap(fu, fv);
            }

            dsu[fv] = fu;
            while(!avail[fv].empty()){
                avail[fu].push_back(avail[fv].back());
                avail[fv].pop_back();
            }
        }
    }

    for(int a = 1; a <= N; a++){
        sort(allof(avail[a]));
    }

    int ans = 0;
    for(int a = 1; a <= N; a++){
        int root = find(a);

        if(binary_search(allof(avail[root]), a)){
            ans++;
        }
    }

    cout << ans;
}
