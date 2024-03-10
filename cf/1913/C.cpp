#include<bits/stdc++.h>

// Created by kobortor On 18:20:56 on 10-03-2024

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 35;
int cnt[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int m;
    cin >> m;
    while (m--) {
        ll t, v;
        cin >> t >> v;
        if (t == 1) {
            cnt[v]++;
        } else {
            bool good = true;
            int carry = 0;
            for (int i = 0; i < 35; i++) {
                carry += cnt[i];
                if (v & (1ll << i)) {
                    carry--;
                }
                if (carry < 0) {
                    good = false;
                    break;
                }
                carry /= 2;
            }

            if (good) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}
