#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n, m, k;
    cin >> n >> m >> k;

    k--;

    cout << k / (2 * m) + 1 << " ";
    k %= 2 * m;

    cout << k / 2 + 1 << " ";
    k %= 2;

    cout << (k == 0 ? "L" : "R");
}
