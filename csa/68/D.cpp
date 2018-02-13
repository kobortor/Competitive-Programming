#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 3005;

struct BIT {
    ll data[2 * MAXN];
    void update(int pos, ll val){
        pos += MAXN;
        while(pos < 2 * MAXN){
            data[pos] += val;
            pos += pos & -pos;
        }
    }
    ll query(int pos){
        pos += MAXN;
        ll ans = 0;
        while(pos){
            ans += data[pos];
            pos -= pos & -pos;
        }
        return ans;
    }
} diag, straight;

int N, Q;

vector<pll> add_diag[MAXN];
vector<pll> add_straight[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> Q;
    while(Q--){
        int R, C, L, S;
        cin >> R >> C >> L >> S;
        add_diag[R].push_back(pll(R - C, S));
        add_diag[R + L].push_back(pll(R - C, -S));

        add_straight[R].push_back(pll(C, S));
        add_straight[R + L].push_back(pll(C, -S));
    }

    ll stot = 0;

    for(int a = 1; a <= N; a++) {
        for(pll p : add_diag[a]){
            diag.update(p.first, p.second);
        }
        for(pll p : add_straight[a]){
            straight.update(p.first, p.second);
            stot += p.second;
        }
        for(int b = 1; b <= N; b++){
            ll ans = diag.query(a - b) - stot + straight.query(b);
            cout << ans << " ";
        }
        cout << endl;
    }
}
