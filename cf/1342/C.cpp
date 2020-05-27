#include<bits/stdc++.h>

// Created by kobortor On 01:06:52 on 27-05-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int prefix[200 * 200];
int a, b, q;

ll upto(ll r) {
    if (r <= 0) return 0;

    return r / (a * b) * prefix[a * b - 1] + prefix[r % (a * b)];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        cin >> a >> b >> q;

        for (int i = 0, cnt = 0; i < a * b; i++) {
            if ((i % a) % b != (i % b) % a) {
                cnt++;
            }

            prefix[i] = cnt;
        }

        while (q--) {
            ll l, r;
            cin >> l >> r;

            cout << upto(r) - upto(l - 1) << " ";
        }
        cout << "\n";
    }
}
