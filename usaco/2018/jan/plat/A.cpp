#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;
const int MAXK = 105;

int N, K;
pii guard[MAXN];

vector<int> uniq;
int dp[MAXN][MAXK];

int rightmost[MAXN];
int cnt[MAXN];
int pre[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    cin >> N >> K;
    K++;

    for(int a = 0; a < N; a++){
        cin >> guard[a].first;
        cin >> guard[a].second;
        uniq.push_back(guard[a].first);
        uniq.push_back(guard[a].second);
    }

    sort(uniq.begin(), uniq.end());
    for(int a = 0; a < N; a++){
        guard[a].first = lower_bound(uniq.begin(), uniq.end(), guard[a].first) - uniq.begin();
        guard[a].second = lower_bound(uniq.begin(), uniq.end(), guard[a].second) - uniq.begin();
    }

    sort(guard, guard + N);
    for(int a = 0; a < N; a++){
        rightmost[guard[a].first] = max(rightmost[guard[a].first], guard[a].second);
        cnt[guard[a].first]++;
    }

    pre[0] = cnt[0];
    for(int a = 1; a < 2 * N; a++){
        rightmost[a] = max(rightmost[a], rightmost[a - 1]);
        pre[a] = pre[a - 1] + cnt[a];
    }

    for(int a = 0; a < 2 * N; a++){
        for(int b = 0; b <= K; b++){
            dp[a][b] = -0x3f3f3f3f;
        }
    }
    dp[0][0] = 0;
    
    for(int a = 0; a < 2 * N; a++){
        for(int fired = K - 1; fired >= 0; fired--){
            dp[a][fired] = max(dp[a][fired], dp[a][fired + 1]);
            //cout << "dp[" << a << "][" << fired << "] = " << dp[a][fired] << endl;
        }
        if(pre[a]){
            int rhs = rightmost[a];
            //do not fire everyone
            int to_fire = pre[rhs] - pre[a - 1];
            for(int fired = 0; fired <= K; fired++){
                dp[rhs][min(K, fired + to_fire - 1)] = max(dp[rhs][min(K, fired + to_fire - 1)], dp[a][fired] + (uniq[rhs] - uniq[a]));
            }
            //cout << a << " jump to " << rhs << " by firing " << to_fire << endl;
        }

        //fire everyone here
        for(int fired = 0; fired <= K; fired++){
            int to_fire = cnt[a];
            dp[a + 1][min(K, fired + to_fire)] = max(dp[a + 1][min(K, fired + to_fire)], dp[a][fired]);
        }
    }

    int ans = 0;
    for(int a = 0; a < 2 * N; a++){
        ans = max(ans, dp[a][K - 1]);
    }
    cout << ans;
}

