#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 4e5 + 5;

ll N, K;

vector<ll> uniq;
vector<pll> segs;
vector<int> prvs[MAXN];

ll dp[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;

    uniq.push_back(0);
    uniq.push_back(N);

    while(K--){
        pll p;
        cin >> p.first >> p.second;

        p.first--;

        uniq.push_back(p.first);
        uniq.push_back(p.second);

        segs.push_back(p);
    }

    sort(allof(uniq));

    uniq.erase(unique(allof(uniq)), uniq.end());

    for(pll p : segs){
        int fr = lower_bound(allof(uniq), p.first) - uniq.begin();
        int bk = lower_bound(allof(uniq), p.second) - uniq.begin();

        prvs[bk].push_back(fr);
    }

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;

    for(int a = 1; a < (int)uniq.size(); a++){
        dp[a] = dp[a - 1] + uniq[a] - uniq[a - 1];
        for(int i : prvs[a]){
            dp[a] = min(dp[i], dp[a]);
        }
    }

    cout << dp[uniq.size() - 1];
}
