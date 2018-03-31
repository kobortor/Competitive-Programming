#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 51;

int N;
int src[MAXN];
int targ[MAXN];

bool dp[MAXN][MAXN];
bool tmp[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> src[a];
        dp[a][src[a]] = true;
    }
    for(int a = 0; a < N; a++){
        cin >> targ[a];
    }
    
    ll ans = 0;

    for(int a = 50; a >= 1; a--){
        memcpy(tmp, dp, sizeof dp);

        //try this many times
        for(int b = 0; b <= a; b++){
            for(int c = 1; c < a; c++){
                for(int d = 0; d < N; d++){
                    for(int e = 0; e <= 50; e++){
                        if(tmp[d][e]){
                            tmp[d][e % c] = true;
                        }
                    }
                }
            }
        }

        bool good = true;
        for(int b = 0; b < N; b++){
            if(!tmp[b][targ[b]]){
                good = false;
                break;
            }
        }
        if(!good){
            //we must use this
            ans += (1ll << (ll)a);
            for(int b = 0; b < N; b++){
                for(int c = 0; c <= 50; c++){
                    if(dp[b][c]){
                        dp[b][c % a] = true;
                    }
                }
            }
        }
    }
    for(int a = 0; a < N; a++){
        if(!dp[a][targ[a]]){
            cout << -1;
            return 0;
        }
    }
    cout << ans;
}
