#include<bits/stdc++.h>

#pragma region template code
using namespace std;
template<typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using maxheap = priority_queue<T>;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const int INF = 0x3f3f3f3f;

const int MAXN = 4e5;

int N;

int fact[10];
int to_int(vector<int> v) {
    int ans = 0;

    for(int a = 0; a < v.size(); a++) {
        int idx = 0;

        for(int b = a + 1; b < v.size(); b++) {
            if(v[b] < v[a]) {
                idx++;
            }
        }

        ans += idx * fact[v.size() - 1 - a];
    }

    return ans;
}

vector<vector<int>> get_adj(vector<int> v) {
    vector<vector<int>> ans;

    for(int start = 0; start < v.size(); start++) {
        for(int len = 1; start + len - 1 < v.size(); len++) {
            vector<int> toedit, tomove;

            for(int a = 0; a < v.size(); a++) {
                if(a < start || start + len <= a) {
                    toedit.push_back(v[a]);
                } else {
                    tomove.push_back(v[a]);
                }
            }

            for(int toins = 0; toins <= toedit.size(); toins++) {
                vector<int> res = toedit;
                res.insert(res.begin() + toins, tomove.begin(), tomove.end());
                ans.push_back(res);
            }
        }
    }

    return ans;
}

int dp[MAXN];
int dp2[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //cin.tie(0);
    //cin.sync_with_stdio(0);
#endif
    fact[0] = 1;

    for(int a = 1; a < 10; a++) {
        fact[a] = fact[a - 1] * a;
    }

    for(int test = 1; true; test++) {
        cin >> N;
        if(N == 0) {
            break;
        }

        fill(dp, dp + fact[N], INF);
        fill(dp2, dp2 + fact[N], INF);

        vector<int> source;
        vector<int> target;

        for(int a = 0; a < N; a++) {
            int x;
            cin >> x;
            source.push_back(x);
            target.push_back(a + 1);
        }

        if(is_sorted(source.begin(), source.end())) {
            cout << "Case " << test << ": " << 0 << "\n";
            continue;
        }

        dp[to_int(source)] = 0;
        vector<vector<int>> step1 = get_adj(source);

        for(vector<int> &v : step1) {
            int pos = to_int(v);
            dp[pos] = min(dp[pos], 1);
            vector<vector<int>> step2 = get_adj(v);

            for(vector<int> &vv : step2) {
                int pos2 = to_int(vv);
                dp[pos2] = min(dp[pos2], 2);
            }
        }

        dp2[to_int(target)] = 0;
        step1 = get_adj(target);

        for(vector<int> &v : step1) {
            int pos = to_int(v);
            dp2[pos] = min(dp2[pos], 1);
            vector<vector<int>> step2 = get_adj(v);

            for(vector<int> &vv : step2) {
                int pos2 = to_int(vv);
                dp2[pos2] = min(dp2[pos2], 2);
            }
        }
        int best = 5;
        for(int a=0; a<fact[N]; a++){
            best = min(best, dp[a] + dp2[a]);
        }
        cout << "Case " << test << ": " << best << "\n";
    }
}
