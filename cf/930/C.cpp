#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, M;
int prefix[MAXN];

struct BIT {
    int data[MAXN];
    void update(int pos, int val){
        pos++;
        while(pos < MAXN){
            data[pos] = max(data[pos], val);
            pos += pos & -pos;
        }
    }
    int query(int pos){
        pos++;
        int ans = 0;
        while(pos){
            ans = max(ans, data[pos]);
            pos -= pos & -pos;
        }
        return ans;
    }
}ds;

int l_inc[MAXN];
int r_inc[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    while(N--){
        int l, r;
        cin >> l >> r;
        prefix[l]++;
        prefix[r + 1]--;
    }
    for(int a = 1; a <= M; a++){
        prefix[a] += prefix[a - 1];
    }

    for(int a = 1; a <= M; a++){
        int val = ds.query(prefix[a]) + 1;
        ds.update(prefix[a], val);
        l_inc[a] = val;
    }
    memset(ds.data, 0, sizeof ds.data);
    for(int a = M; a >= 1; a--){
        int val = ds.query(prefix[a]) + 1;
        ds.update(prefix[a], val);
        r_inc[a] = val;
    }

    int ans = 0;
    int best = 0;
    for(int a = 1; a <= M; a++){
        ans = max(ans, best + r_inc[a]);
        best = max(best, l_inc[a]);
        ans = max(ans, best);
    }
    cout << ans;
}
