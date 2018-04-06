#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 72;

ll N, K;

//dp[L][R][freed]
ll dp[MAXN][MAXN][MAXN];
ll key[MAXN], prio[MAXN], access[MAXN];
vector<pii> prio_list[MAXN][MAXN];
ll acc_sum[MAXN][MAXN];

ll dfs(int l, int r, int lim){ 
    if(l >= r){
        return 0;
    }
    assert(0 <= lim && lim < MAXN);
    if(dp[l][r][lim] != -1){
        return dp[l][r][lim];
    }

    int num_abv = 0;
    for(pii p : prio_list[l][r]){
        if(p.first > lim){
            num_abv++;
        }
    }

    dp[l][r][lim] = 1e18;
    for(int a = 0; a < (int)prio_list[l][r].size(); a++){
        int pri = prio_list[l][r][a].first;
        int idx = prio_list[l][r][a].second;

        ll base_cost = acc_sum[l][r] - access[idx];

        if(pri > lim){
            dp[l][r][lim] = min(dp[l][r][lim], dfs(l, idx - 1, lim) + dfs(idx + 1, r, lim) + base_cost);
        } else {
            ll extra_cost = (prio_list[l][r].size() - a - 1 - num_abv) * K;

            dp[l][r][lim] = min(dp[l][r][lim], dfs(l, idx - 1, pri) + dfs(idx + 1, r, pri) + base_cost + extra_cost);
            dp[l][r][lim] = min(dp[l][r][lim], dfs(l, idx - 1, lim) + dfs(idx + 1, r, lim) + base_cost + K); //put this on top
        }
    }
    return dp[l][r][lim];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;

    vector<int> uniqk;
    for(int a = 0; a < N; a++){
        cin >> key[a];
        uniqk.push_back(key[a]);
    }
    sort(allof(uniqk));
    for(int a = 0; a < N; a++){
        key[a] = lower_bound(allof(uniqk), key[a]) - uniqk.begin();
    }

    vector<int> uniqp;
    for(int a = 0; a < N; a++){
        cin >> prio[key[a]];
        prio[key[a]] = N - prio[key[a]] - 1;
        uniqp.push_back(prio[key[a]]);
    }
    sort(allof(uniqp));
    for(int a = 0; a < N; a++){
        prio[a] = lower_bound(allof(uniqp), prio[a]) - uniqp.begin();
    }
    for(int a = 0; a < N; a++){
        cin >> access[key[a]];
    }
    for(int l = 0; l < N; l++){
        for(int r = l; r < N; r++){
            for(int i = l; i <= r; i++){
                prio_list[l][r].push_back(pii(prio[i], i));
                acc_sum[l][r] += access[i];
            }
            sort(allof(prio_list[l][r]));
        }
    }
    memset(dp, -1, sizeof dp);
    dfs(0, N - 1, MAXN - 1);
    cout << dp[0][N - 1][MAXN - 1] + acc_sum[0][N - 1];
}
