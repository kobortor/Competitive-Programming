#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll N, M, A, B;
    cin >> N >> M >> A >> B;
    cout << min(N % M * B, (M - N % M) * A);
}
