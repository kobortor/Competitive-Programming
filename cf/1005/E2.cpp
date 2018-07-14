#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N, M;

int arr[MAXN];

struct BIT {
    int data[MAXN * 2];

    void update(int pos, int val){
        pos += MAXN;
        while(pos < MAXN * 2){
            data[pos] += val;
            pos += pos & -pos;
        }
    }

    int query(int pos){
        pos += MAXN;
        int ans = 0;
        while(pos){
            ans += data[pos];
            pos -= pos & -pos;
        }
        return ans;
    }
} ds[2];

ll solve(bool is_less){
    memset(ds[0].data, 0, sizeof ds[0].data);
    memset(ds[1].data, 0, sizeof ds[1].data);

    ds[0].update(0, 1);

    ll res = 0;

    for(int a = 1, tot = 0; a <= N; a++){
        if(a % 2 == 1){
            tot--;
        }

        if(is_less){
            tot += arr[a] < M;
        } else {
            tot += arr[a] > M;
        }

        ll tmp0, tmp1;
        if(a % 2 == 0){
            tmp0 = ds[0].query(tot - !is_less);
            tmp1 = ds[1].query(tot - 1);
        } else {
            tmp0 = ds[1].query(tot - !is_less);
            tmp1 = ds[0].query(tot);
        }

        res += tmp0 + tmp1;

        ds[a % 2].update(tot, 1);
    }

    return res;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    for(int a = 1; a <= N; a++){
        cin >> arr[a];
    }

    ll ans = (ll)N * (N + 1) / 2;

    ans -= solve(true);
    ans -= solve(false);

    cout << ans;
}
