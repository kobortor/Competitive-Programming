#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, M;
int dp[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    int prv;
    cin >> prv;

    int lft = 1;
    for(int a = 2; a <= N; a++){
        int cur;
        cin >> cur;
        if(prv > cur){
            lft = a;
        }

        if(prv >= cur){
            dp[a] = min(dp[a - 1], lft);
        } else {
            dp[a] = lft;
        }

        prv = cur;
    }

    while(M--){
        int l, r;
        cin >> l >> r;
        if(l >= dp[r]){
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}
