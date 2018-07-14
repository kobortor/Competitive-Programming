#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2005;

int N, K, Q;
int arr[MAXN];

pii sorted[MAXN];

struct BIT {
    int data[MAXN];
    void update(int pos, int val){
        while(pos < MAXN){
            data[pos] += val;
            pos += pos & -pos;
        }
    }

    int query(int pos){
        int ans = 0;
        while(pos){
            ans += data[pos];
            pos -= pos & -pos;
        }
        return ans;
    }
}ds;

int solve(int lowv){
    memset(ds.data, 0, sizeof ds.data);

    for(int a = 1; a <= N; a++){
        ds.update(a, 1);
    }

    set<int> illegal;
    illegal.insert(0);
    illegal.insert(N + 1);

    int used = 0;

    for(int a = 1; a <= N; a++){
        if(sorted[a].first < lowv){
            illegal.insert(sorted[a].second);
            ds.update(sorted[a].second, -1);
        } else {
            auto iter = illegal.lower_bound(sorted[a].second);
            int lft = *prev(iter);
            int rht = *iter;
            if(ds.query(rht) - ds.query(lft) >= K){
                //good
                used++;
                if(used == Q) {
                    return sorted[a].first - lowv;
                }
            }
            ds.update(sorted[a].second, -1);
        }
    }
    return 1e9;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K >> Q;
    for(int a = 1; a <= N; a++){
        cin >> arr[a];
        sorted[a] = pii(arr[a], a);
    }

    sort(sorted + 1, sorted + N + 1);

    int ans = 1e9;
    for(int a = 1; a <= N; a++){
        ans = min(ans, solve(arr[a]));
    }
    cout << ans;
}
