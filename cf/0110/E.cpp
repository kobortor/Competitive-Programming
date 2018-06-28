#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

bool lucky(int x){
    while(x){
        if(x % 10 != 4 && x % 10 != 7){
            return false;
        }
        x /= 10;
    }
    return true;
}

int dsu[MAXN];
int sz[MAXN];

int find(int x){
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

int N;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    for(int a = 1; a <= N; a++){
        dsu[a] = a;
        sz[a] = 1;
    }

    for(int a = 1; a <= N - 1; a++){
        int u, v, c;
        cin >> u >> v >> c;
        if(!lucky(c)){
            int fu = find(u);
            int fv = find(v);

            dsu[fu] = fv;
            sz[fv] += sz[fu];
        }
    }

    ll ans = (ll)N * (N - 1) * (N - 2);

    for(int a = 1; a <= N; a++){
        if(dsu[a] == a){
            ll tmp = sz[a];

            ans -= tmp * (tmp - 1) * (tmp - 2);
            ans -= 2 * tmp * (tmp - 1) * (N - tmp);
        }
    }

    cout << ans;
}
