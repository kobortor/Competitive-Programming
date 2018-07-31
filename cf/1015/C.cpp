#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

ll N, M, tot;
ll comp[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 0; a < N; a++){
        ll x, y;
        cin >> x >> y;
        tot += x;
        comp[a] = x - y;
    }

    sort(comp, comp + N);
    reverse(comp, comp + N);

    if(tot <= M){
        cout << 0;
        return 0;
    }

    for(int a = 0; a < N; a++){
        tot -= comp[a];
        if(tot <= M){
            cout << a + 1;
            return 0;
        }
    }

    cout << -1;
}
