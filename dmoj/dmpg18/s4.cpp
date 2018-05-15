#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N;

int sz[MAXN];
int dsu[MAXN];
int arr[MAXN];

int find(int x){
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        cin >> arr[a];
        sz[a] = 1;
        dsu[a] = a;
    }

    for(int a = 1; a <= N - 1; a++){
        int u, v;
        cin >> u >> v;
        if((arr[u] + arr[v]) & 1){
            int fu = find(u);
            int fv = find(v);
            if(fu != fv){
                dsu[fu] = fv;
                sz[fv] += sz[fu];
            }
        }
    }

    ll ans = 0;
    for(int a = 1; a <= N; a++){
        if(arr[a] & 1){
            ans += sz[find(a)];
        }
    }
    cout << ans;
}
