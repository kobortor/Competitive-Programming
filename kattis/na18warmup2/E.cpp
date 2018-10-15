#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXS = 924;

vector<vector<int>> states;
vector<int> adj[MAXS];

vector<int> cur;
void recur(int pos, int hel){
    if(pos == 6){
        states.push_back(cur);
        return;
    }

    cur.push_back(hel);
    recur(pos + 1, hel);
    cur.pop_back();

    if(hel != 6){
        recur(pos, hel + 1);
    }
}

double dp[MAXS][MAXS];
double nxtdp[MAXS][MAXS];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    recur(0, 0);
    for(int a = 0; a < (int)states.size(); a++){
        for(int j = 0; j < (int)states[0].size(); j++){
            if(states[a][j]){
                vector<int> v = states[a];
                v[j]--;
                sort(allof(v));

                adj[a].push_back(lower_bound(allof(states), v) - states.begin());
            }
        }
    }

    int N, M, D;
    cin >> N >> M >> D;

    int tot = 0;

    vector<int> me(6), enemy(6);
    for(int a = 0; a < N; a++){
        cin >> me[a];
        tot += me[a];
    }
    for(int a = 0; a < M; a++){
        cin >> enemy[a];
        tot += enemy[a];
    }

    if(D >= tot){
        cout << 1 << endl;
        return 0;
    }

    sort(allof(me));
    sort(allof(enemy));

    int my_id = lower_bound(allof(states), me) - states.begin();
    int enemy_id = lower_bound(allof(states), enemy) - states.begin();

    dp[my_id][enemy_id] = 1;

    while(D--){
        for(int a = 0; a < MAXS; a++){
            for(int b = 0; b < MAXS; b++){
                if(dp[a][b] == 0){
                    continue;
                }
                vector<pii> nxt;
                for(int i : adj[a]){
                    nxt.push_back(pii(i, b));
                }
                for(int i : adj[b]){
                    nxt.push_back(pii(a, i));
                }

                if(nxt.empty()){
                    //avoid div 0 errors
                    continue;
                } else {
                    for(pii p : nxt){
                        nxtdp[p.first][p.second] += dp[a][b] / nxt.size();
                    }
                }
            }
        }

        for(int a = 0; a < MAXS; a++){
            copy(nxtdp[a], nxtdp[a] + MAXS, dp[a]);
            fill(nxtdp[a], nxtdp[a] + MAXS, 0.0);
        }
    }

    double ans = 0;
    for(int a = 0; a < MAXS; a++){
        ans += dp[a][0];
    }

    cout << fixed << setprecision(15) << ans << endl;
}
