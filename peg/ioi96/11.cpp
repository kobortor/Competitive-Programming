#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 205;

int N;
int arr[MAXN];
int dp[MAXN][MAXN];

int recur(int l, int r, int p){
    if(l > r){
        return 0;
    }

    if(dp[l][r] != 0x3f3f3f3f){
        return dp[l][r];
    }

    if(p == 1){
        return dp[l][r] = max(recur(l + 1, r, 2) + arr[l], recur(l, r - 1, 2) + arr[r]);
    } else {
        return dp[l][r] = min(recur(l + 1, r, 1) - arr[l], recur(l, r - 1, 1) - arr[r]);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(dp, 0x3f, sizeof dp);

    cin >> N;

    int tot = 0;
    for(int a = 0; a < N; a++){
        cin >> arr[a];
        tot += arr[a];
    }

    int diff = recur(0, N - 1, 1);
    cout << (tot + diff) / 2 << " " << (tot - diff) / 2;
}
