#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int red[7] = {0, 1, 0, 0, 1, 0, 0};

    int a, b; cin >> a >> b;

    int ok = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            for (int k = 1; k <= 6; k++) {
                
                int cnt[2] = {};
                cnt[red[i]] += i;
                cnt[red[j]] += j;
                cnt[red[k]] += k;

                if (cnt[1] == a && cnt[0] == b) ok = 1;

            }
        }
    }

    cout << (ok ? "Yes\n" : "No\n");

}
