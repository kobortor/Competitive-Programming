#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    ll sz = n / m;
    ll extra = n - sz * m;

    cout << sz * (sz - 1) / 2 * m + extra * sz << " ";
    cout << (n - m + 1) * (n - m) / 2;
}
