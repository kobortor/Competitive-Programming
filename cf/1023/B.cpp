#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N, K;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;

    N = min(N, K - 1);

    ll ans = N - (K - N) + 1;

    if(K % 2 == 0 && K / 2 <= N){
        ans--;
    }

    cout << max(ans / 2, 0ll);
}
