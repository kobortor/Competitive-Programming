#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
ll arr[MAXN];
ll dp[2];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    while(N--){
        int x;
        cin >> x;
        arr[x]++;
    }

    for(int a = 1; a < MAXN; a++){
        ll tmp = dp[0] + a * arr[a];
        dp[0] = max(dp[0], dp[1]);
        dp[1] = max(dp[1], tmp);
    }
    cout << *max_element(dp, dp + 2);
}
