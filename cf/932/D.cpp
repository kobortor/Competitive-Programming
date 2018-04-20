#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 4e5 + 5;

ll Q;
ll last = 0;

ll cnt = 1;
ll wt[MAXN];
ll jmp[MAXN][20];
ll jmpcost[MAXN][20];
ll jmpmax[MAXN][20];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(jmp, -1, sizeof jmp);

    cin >> Q;

    jmp[1][0] = 0;

    while(Q--){
        ll tp, R, W;
        cin >> tp >> R >> W;
        R ^= last;
        W ^= last;

        if(tp == 1){
            cnt++;
            
            wt[cnt] = W;

            if(wt[R] < wt[cnt]){
                for(int a = 19; a >= 0; a--){
                    if(jmp[R][a] != -1){
                        if(jmpmax[R][a] < W){
                            R = jmp[R][a];
                        }
                    }
                }
            }
            //cout << "Added branch from " << R << " to " << cnt << " costing " << W << endl;
            
            jmp[cnt][0] = R;
            jmpcost[cnt][0] = W;
            jmpmax[cnt][0] = W;

            for(int a = 1; a < 20; a++){
                if(jmp[cnt][a-1] == -1){
                    break;
                }
                jmp[cnt][a] = jmp[jmp[cnt][a-1]][a-1];
                jmpcost[cnt][a] = jmpcost[cnt][a-1] + jmpcost[jmp[cnt][a-1]][a-1];
                jmpmax[cnt][a] = max(jmpmax[cnt][a-1], jmpmax[jmp[cnt][a-1]][a-1]);
            }
        } else {
            //cout << "Query " << R << " " << W << endl;
            ll ans = 0;
            for(int a = 19; a >= 0; a--){
                if(jmp[R][a] != -1 && W >= jmpcost[R][a]){
                    W -= jmpcost[R][a];
                    R = jmp[R][a];
                    ans += 1 << a;
                }
            }
            cout << ans << "\n";
            last = ans;
        }
    }
}
