#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

vector<ll> uniq;
ll arr[MAXN];

ll N, K;

struct {
    int data[MAXN];
    void update(int pos){
        while(pos < MAXN){
            data[pos]++;
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
} ds;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;

    uniq.push_back(-1e18);
    for(int a = 1; a <= N; a++){
        cin >> arr[a];
        arr[a] += arr[a - 1] - K;
        uniq.push_back(arr[a]);
    }
    sort(allof(uniq));

    ll ans = 0;
    for(int a = 0; a <= N; a++){
        int x = lower_bound(allof(uniq), arr[a]) - uniq.begin();
        ans += ds.query(x);
        ds.update(x);
    }
    cout << ans;
}
