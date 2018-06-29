#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, M;
int val[MAXN];
int prefix[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    for(int a = 1; a <= N; a++){
        cin >> val[a];
    }
    val[N + 1] = M;

    int tot = 0;

    for(int a = 1; a <= N + 1; a += 2){
        tot += val[a] - val[a - 1];
        prefix[a] = tot;
    }

    int ans = prefix[N + 1];

    for(int a = 1; a <= N; a += 2){
        ans = max(ans, 2 * prefix[a] + M - val[a] - tot - 1);
    }
    cout << ans << "\n";
}
