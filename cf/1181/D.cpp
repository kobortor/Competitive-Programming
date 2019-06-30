#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<cassert>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = (1 << 19);

int N, M, Q;

int cnt[MAXN];
vector<int> freq[MAXN];

int ans[MAXN];

struct BIT {
    int data[MAXN];
    void add(int x) {
        while (x < MAXN) {
            data[x]++;
            x += x & -x;
        }
    }
    int sum(int n) {
        int ans = 0;
        while (n) {
            ans += data[n];
            n -= n & -n;
        }
        return ans;
    }
    int find_nth(int n) {
        int orign = n;
        int idx = 0;
        for (int a = 18; a >= 0; a--) {
            if (data[idx | (1 << a)] < n) {
                n -= data[idx | (1 << a)];
                idx |= 1 << a;
            } else {
                //ignore
            }
        }

        assert(sum(idx + 1) == orign && sum(idx) == orign - 1);
        return idx + 1;
    }
} ds;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> Q;

    for (int a = 1; a <= N; a++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    for (int a = 1; a <= M; a++) {
        freq[cnt[a]].push_back(a);
    }

    vector<pll> queries;
    for (int a = 1; a <= Q; a++) {
        ll x;
        cin >> x;
        queries.push_back({x, a});
    }
    sort(allof(queries));

    ll stored = 0;
    int cur_qr = 0;
    ll cur_tm = N;
    for (int a = 0; a < MAXN; a++) {
        ll nxt_tm = cur_tm + stored;
        while (cur_qr < Q && queries[cur_qr].first <= nxt_tm) {
            ans[queries[cur_qr].second] = ds.find_nth(queries[cur_qr].first - cur_tm);
            //cout << "Current time " << cur_tm << endl;
            //cout << "Solve qtime = " << queries[cur_qr].first << " answer = " << ans[queries[cur_qr].second] << " by looking for " << cur_tm << endl;
            cur_qr++;
        }

        for (int i : freq[a]) {
            //cout << "Add in " << i << endl;
            ds.add(i);
            stored++;
        }
        cur_tm = nxt_tm;
    }

    while (cur_qr < Q) {
        ll diff = queries[cur_qr].first - cur_tm;
        diff %= M;
        ans[queries[cur_qr].second] = ds.find_nth(diff == 0 ? M : diff);

        cur_qr++;
    }

    for (int a = 1; a <= Q; a++) {
        cout << ans[a] << "\n";
    }
}
