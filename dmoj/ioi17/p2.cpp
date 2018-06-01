#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;
ll dp[MAXN];
ll bestover[MAXN];
ll bestunder[MAXN];

long long min_total_length(vector<int> R, vector<int> B){
    vector<pii> vec(R.size() + B.size() + 1);
    vec[0] = pii(-1e9, -1);

    vector<pii> _R(R.size()), _B(B.size());
    for(int a = 0; a < (int)R.size(); a++){
        _R[a] = pii(R[a], 0);
    }
    for(int a = 0; a < (int)B.size(); a++){
        _B[a] = pii(B[a], 1);
    }

    merge(_R.begin(), _R.end(), _B.begin(), _B.end(), vec.begin() + 1);

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    
    int prvpos = 0;
    int backlim = 0;
    ll accum = 0;

    for(int a = 1; a < (int)vec.size(); a++){
        if(vec[a].second != vec[a - 1].second){
            accum = 0;

            ll gap = vec[a].first - vec[a - 1].first;
            ll tot = 0;
            for(int b = a - 1; b >= prvpos; b--){
                tot += vec[a - 1].first - vec[b].first;
                bestover[b] = tot + (a - b) * gap + min((b == 0 ? 0ll : dp[b - 1]), dp[b]);
                bestunder[b] = tot + min((b == 0 ? 0ll : dp[b - 1]), dp[b]);
            }

            for(int b = prvpos + 1; b <= a - 1; b++){
                bestover[b] = min(bestover[b], bestover[b - 1]);
            }
            for(int b = a - 2; b >= prvpos; b--){
                bestunder[b] = min(bestunder[b], bestunder[b + 1]);
            }

            backlim = prvpos;
            prvpos = a;
        }

        accum += vec[a].first - vec[prvpos].first;

        if(backlim != 0){
            ll gap = vec[prvpos].first - vec[prvpos - 1].first;

            int len = a - prvpos + 1;
            int back = max(backlim, prvpos - len);

            //can always under
            dp[a] = bestunder[back] + len * gap + accum;

            if(backlim <= prvpos - len){
                dp[a] = min(dp[a], bestover[back] + accum);
            }
        }
    }

    return dp[vec.size() - 1];
}
