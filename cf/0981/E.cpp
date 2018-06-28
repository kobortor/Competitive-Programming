#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e4 + 4;
const ll mod = 1e9 + 7;
const ll mod2 = 1e9 + 9;

int N, Q;

vector<int> add[MAXN], rem[MAXN];

ll dp[MAXN];
ll dp2[MAXN];
bool ans[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> Q;
    
    while(Q--){
        int l, r, x;
        cin >> l >> r >> x;
        add[l].push_back(x);
        rem[r].push_back(x);
    }

    dp[0] = 1;
    dp2[0] = 1;
    for(int a = 1; a <= N; a++){
        for(int i : add[a]){
            for(int j = N; j >= i; j--){
                dp[j] += dp[j - i];
                dp[j] %= mod;

                dp2[j] += dp2[j - i];
                dp2[j] %= mod2;
            }
        }

        for(int b = 1; b <= N; b++){
            if(dp[b] || dp2[b]){
                ans[b] = true;
            }
        }

        for(int i : rem[a]){
            for(int j = i; j <= N; j++){
                dp[j] -= dp[j - i];
                if(dp[j] < 0){
                    dp[j] += mod;
                }

                dp2[j] -= dp2[j - i];
                if(dp2[j] < 0){
                    dp2[j] += mod2;
                }
            }
        }
    }

    vector<int> out;
    for(int a = 1; a <= N; a++){
        if(ans[a]){
            out.push_back(a);
        }
    }
    cout << out.size() << "\n";
    for(int i : out){
        cout << i << " ";
    }
}
