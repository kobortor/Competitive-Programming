#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N;
ll prefix[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    for(int a = 1; a <= N; a++){
        cin >> prefix[a];
        prefix[a] += prefix[a-1];
    }

    ll ans = 0;
    for(int a = 1; a <= N; a++){
        ans += prefix[N - a + 1];
        ans -= prefix[a - 1];
        cout << ans << "\n";
    }
}
