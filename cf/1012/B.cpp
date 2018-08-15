#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 4e5 + 5;

int N, M, Q;

int dsu[MAXN];
int find(int x){
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> Q;

    for(int a = 1; a <= N + M; a++){
        dsu[a] = a;
    }

    int ans = N + M - 1;

    while(Q--){
        int r, c;
        cin >> r >> c;

        int fu = find(r);
        int fv = find(c + N);
        if(fu != fv){
            dsu[fu] = fv;
            ans--;
        }
    }

    cout << ans;
}
