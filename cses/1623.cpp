#include<bits/stdc++.h>

// Created by kobortor On 18:48:08 on 27-01-2024

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> p(n);
    for (int &pi : p) cin >> pi;

    ll ans = 1e15;
    for (int state = 0; state < (1 << n); state++) {
        ll diff = 0;
        for (int i = 0; i < n; i++) {
            if (state & (1 << i)) {
                diff += p[i];
            } else {
                diff -= p[i];
            }
        }
        ans = min(ans, abs(diff));
    }
    cout << ans;
}
