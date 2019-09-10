#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int phi (int N, int q) {
    if (N == 1) return 1;
    int K = N / 2;
    if (q <= K) {
        return (N - K) + phi (K, K - q + 1);
    } else {
        return phi (N - K, N - q + 1);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, q;
    cin >> N >> q;
    cout << phi(N, q);
}
