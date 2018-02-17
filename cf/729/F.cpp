#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 4005;
const int SQRT = 65;

int N;

ll arr[MAXN];
ll pfront[MAXN];
ll pback[MAXN];

//[turn][l][d][k]
bool seen[2][MAXN][2 * SQRT][SQRT];
ll dp[2][MAXN][SQRT][SQRT];

ll solve(int turn, int l, int r, int k){
    if(l + k >= r){
        return pfront[l] - pback[r]; //cannot continue
    }
    int d = (N + 1 - r) - l;
    if(seen[turn][l][d + SQRT][k]){
        return dp[turn][l][d + SQRT][k];
    }
    
    ll best = turn ? 99999999 : -99999999;
    if(turn){ //approaching from right
        if(l + k < r){
            best = min(best, solve(!turn, l, r - k, k));
        }
        if(l + k + 1 < r){
            best = min(best, solve(!turn, l, r - (k + 1), k + 1));
        }
    } else { //approaching from left
        if(l + k < r){
            best = max(best, solve(!turn, l + k, r, k));
        }
        if(l + k + 1 < r){
            best = max(best, solve(!turn, l + (k + 1), r, k + 1));
        }       
    }
    seen[turn][l][d + SQRT][k] = true;
    return dp[turn][l][d + SQRT][k] = best;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        cin >> arr[a];
    }
    for(int a = 1; a <= N; a++){
        pfront[a] = arr[a] + pfront[a - 1];
    }
    for(int a = N; a >= 1; a--){
        pback[a] = arr[a] + pback[a + 1];
    }

    cout << solve(0, 0, N + 1, 1);
}
