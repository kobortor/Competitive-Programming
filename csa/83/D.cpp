#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

ll N, A;

vector<ll> points[MAXN];

struct BIT {
    ll data[MAXN];

    void update(ll pos, ll val){
        while(pos < MAXN){
            data[pos] += val;
            pos += pos & -pos;
        }
    }

    ll query(ll pos){
        ll ans = 0;
        while(pos){
            ans += data[pos];
            pos -= pos & -pos;
        }
        return ans;
    }
} ds;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> A;
    
    while(N--){
        ll x, y;
        cin >> x >> y;
        points[x].push_back(y);
    }

    ll ans = 0;
    for(int a = 1; a < MAXN; a++){
        for(ll y : points[a]){
            ds.update(y, 1);
        }

        ans = max(ans, ds.query(min(A / a, (ll)MAXN - 1)));
    }
    
    cout << ans;
}
