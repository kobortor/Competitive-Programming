#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, V;
    cin >> N >> V;

    int ans = min(N - 1, V);
    for (int a = 2; a + V <= N; a++) {
        ans += a;
    }

    cout << ans;
}
