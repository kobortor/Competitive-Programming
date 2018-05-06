#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 12;
const int SIZE = 400;
const int MOD = 1e8;

int R, C;
int grid[MAXN];

int dp[MAXN][SIZE];

vector<int> nums;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> R >> C;
    for(int a = 0; a < R; a++){
        for(int b = 0; b < C; b++){
            int v;
            cin >> v;
            if(v){
                grid[a] |= 1 << b;
            }
        }
    }

    for(int a = 0; a < (1 << C); a++){
        bool good = true;
        bool prv = false;
        for(int b = 0; b < C; b++){
            if((a >> b) & 1){
                if(prv){
                    good = false;
                    break;
                } else {
                    prv = true;
                }
            } else {
                prv = false;
            }
        }
        if(good){
            nums.push_back(a);
        }
    }

    for(int a = 0; a < (int)nums.size(); a++){
        if((nums[a] & grid[0]) == nums[a]){
            dp[0][a] = 1;
        }
    }
    for(int a = 1; a < R; a++){
        for(int i = 0; i < (int)nums.size(); i++){
            if((nums[i] & grid[a]) != nums[i]){
                continue;
            }
            for(int j = 0; j < (int)nums.size(); j++){
                if(nums[i] & nums[j]){
                    continue;
                }
                dp[a][i] += dp[a-1][j];
                dp[a][i] %= MOD;
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < (int)nums.size(); i++){
        ans += dp[R-1][i];
        ans %= MOD;
    }
    cout << ans << "\n";
}
