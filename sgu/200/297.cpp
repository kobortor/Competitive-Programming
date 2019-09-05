#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int N, M;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    int ans = 0;
    while (M--) {
        int Si;
        cin >> Si;

        ans += Si;
    }

    cout << ans % N;
}
