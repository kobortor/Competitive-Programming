#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 505;
const int MAXK = 12;
const int MAXV = 1e5 + 5;

int N, K;
int card[MAXV];
int fav[MAXV];
int joy[MAXK];

int dp[MAXV];
int solve(int player, int freq){
    memset(dp, 0xaf, sizeof dp);
    dp[0] = 0;

    for(int a = 0; a < player; a++){
        for(int b = freq; b >= 0; b--){
            for(int c = 0; c <= K && c <= b; c++){
                dp[b] = max(dp[b], dp[b - c] + joy[c]);
            }
        }
    }

    return *max_element(dp, dp + MAXV);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;
    for(int a = 1; a <= N * K; a++){
        int x;
        cin >> x;
        card[x]++;
    }

    for(int a = 1; a <= N; a++){
        int x;
        cin >> x;
        fav[x]++;
    }

    for(int a = 1; a <= K; a++){
        cin >> joy[a];
    }

    int ans = 0;
    for(int a = 0; a < MAXV; a++){
        if(card[a] != 0 && fav[a] != 0){
            ans += solve(fav[a], card[a]);
        }
    }

    cout << ans;
}
