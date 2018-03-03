#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 101;
const int MAXT = 2001;

struct poke {
    int pos, val, tm;
    poke(){}
    poke(int p, int v, int t){
        pos = p;
        val = v;
        tm = t;
    }
};

int N, K, M;

vector<poke> lft, rht;

int dp[MAXN][MAXN][2][MAXT];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    //dummy padding
    rht.push_back(poke(K, 0, 0));

    int still = 0;

    cin >> N >> K >> M;
    for(int a = 0; a < M; a++){
        poke mon;
        cin >> mon.pos >> mon.val >> mon.tm;
        if(mon.pos == K){
            still = mon.val;
        } else if (mon.pos < K){
            lft.push_back(mon);
        } else {
            rht.push_back(mon);
        }
    }

    lft.push_back(poke(K, 0, 0));
    reverse(allof(lft));

    for(int a = 0; a < MAXN; a++){
        for(int b = 0; b < MAXN; b++){
            for(int t = 0; t < MAXT; t++){
                dp[a][b][0][t] = -1e9;
                dp[a][b][1][t] = -1e9;
            }
        }
    }

    dp[0][0][0][0] = 0;

    for(int a = 0; a < (int)lft.size(); a++){
        for(int b = 0; b < (int)rht.size(); b++){
            for(int t = 0; t < MAXT; t++){
                //from left
                if(a + 1 != (int)lft.size()){
                    int ntm = t + abs(lft[a + 1].pos - lft[a].pos);
                    if(ntm < MAXT){
                        int newsum = dp[a][b][0][t];
                        if(ntm < lft[a + 1].tm){
                            newsum += lft[a + 1].val;
                        }
                        dp[a + 1][b][0][ntm] = max(dp[a + 1][b][0][ntm], newsum);
                    }
                }
                if(b + 1 != (int)rht.size()){
                    int ntm = t + abs(rht[b + 1].pos - lft[a].pos);
                    if(ntm < MAXT){
                        int newsum = dp[a][b][0][t];
                        if(ntm < rht[b + 1].tm){
                            newsum += rht[b + 1].val;
                        }
                        dp[a][b + 1][1][ntm] = max(dp[a][b + 1][1][ntm], newsum);
                    }
                }

                //from right
                if(a + 1 != (int)lft.size()){
                    int ntm = t + abs(lft[a + 1].pos - rht[b].pos);
                    if(ntm < MAXT){
                        int newsum = dp[a][b][1][t];
                        if(ntm < lft[a + 1].tm){
                            newsum += lft[a + 1].val;
                        }
                        dp[a + 1][b][0][ntm] = max(dp[a + 1][b][0][ntm], newsum);
                    }
                }
                if(b + 1 != (int)rht.size()){
                    int ntm = t + abs(rht[b + 1].pos - rht[b].pos);
                    if(ntm < MAXT){
                        int newsum = dp[a][b][1][t];
                        if(ntm < rht[b + 1].tm){
                            newsum += rht[b + 1].val;
                        }
                        dp[a][b + 1][1][ntm] = max(dp[a][b + 1][1][ntm], newsum);
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int a = 0; a < (int)lft.size(); a++){
        for(int b = 0; b < (int)rht.size(); b++){
            for(int t = 0; t < MAXT; t++){
                ans = max(ans, dp[a][b][0][t]);
                ans = max(ans, dp[a][b][1][t]);
            }
        }
    }
    cout << ans + still;

}
