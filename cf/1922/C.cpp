#include<bits/stdc++.h>

// Created by kobortor On 18:48:54 on 21-01-2024

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;
ll A[MAXN];
ll prefixL[MAXN];
ll prefixR[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        A[0] = -1e10;
        A[n+1] = +1e10;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }
        for (int i = 1; i <= n; i++) {
            if (A[i] - A[i-1] < A[i+1] - A[i]) {
                // shorter is left
                prefixL[i] = A[i] - A[i-1] - 1;
                prefixR[i] = 0;
            } else {
                prefixL[i] = 0;
                prefixR[i] = A[i+1] - A[i] - 1;
            }
            prefixL[i] += prefixL[i-1];
            prefixR[i] += prefixR[i-1];
        }

        int m;
        cin >> m;
        while (m--) {
            int i, j;
            cin >> i >> j;

            ll ans = abs(A[i] - A[j]);
            if (i < j) {
                ans -= prefixR[j-1] - prefixR[i-1];
            } else {
                ans -= prefixL[i] - prefixL[j];
            }

            cout << ans << "\n";
        }
    }
}
