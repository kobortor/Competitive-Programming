#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXP = 35;
const int MAXN = 305;

int V, P;
int pos[MAXN];
int cost[MAXN][MAXN];
pii dp[MAXP][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> V >> P;

    for(int a = 1; a <= V; a++){
        cin >> pos[a];
    }
    
    for(int a = 1; a <= V; a++){
        cost[a][a] = 0;

        int cur = a;
        int mid = a;
        int tot = 0;

        while(cur + 1 <= V){
            cur++;
            tot += pos[cur] - pos[mid];

            while(cur - mid > mid - a){
                tot += (pos[mid + 1] - pos[mid]) * ((mid + 1 - a) - (cur - mid));

                mid++;
            }

            cost[a][cur] = tot;
        }
    }

    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = pii(0, 0);

    for(int a = 1; a <= P; a++){
        for(int b = 1; b <= V; b++){
            for(int c = 1; c <= b; c++){
                dp[a][b] = min(dp[a][b], pii(dp[a - 1][c - 1].first + cost[c][b], c));
            }
        }
        memcpy(dp[0], dp[1], sizeof dp[1]);
    }

    cout << dp[P][V].first << "\n";

    vector<int> soln;
    int cur = V;
    for(int a = P; a >= 1; a--){
        int prv = dp[a][cur].second;
        soln.push_back(pos[(cur + prv) / 2]);

        cur = prv - 1;
    }

    reverse(allof(soln));

    for(int i : soln){
        cout << i << " ";
    }
}
