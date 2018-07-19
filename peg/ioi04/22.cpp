#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 150005;
const int MAXM = 2005;

int Q;
bool dp[MAXN];

int M, K;
int fields[MAXM];
int strips[MAXM];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> Q >> M >> K;

    dp[0] = true;

    int tot = 0;
    for(int a = 1; a <= M; a++){
        cin >> fields[a];

        tot += fields[a];

        for(int b = Q; b >= fields[a]; b--){
            dp[b] |= dp[b - fields[a]];
        }
    }

    if(dp[Q]){
        cout << Q;
        return 0;
    }

    if(tot > Q){
        cout << Q - 1;
        return 0;
    }

    for(int a = 1; a <= M; a++){
        cin >> strips[a];
    }

    sort(strips + 1, strips + M + 1);
    reverse(strips + 1, strips + M + 1);

    for(int a = 1; a <= M; a++){
        tot += strips[a];
        
        if(tot >= Q){
            cout << Q - a;
            return 0;
        }
    }

    cout << tot - M;
}
