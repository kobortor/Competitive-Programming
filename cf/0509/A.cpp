#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll fact(ll n) {
    return (!n) ? (ll)1 : n * fact(n - 1);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n;
    cin >> n;
    n--;
    cout << fact(2 * n) / fact(n) / fact(n);
}
