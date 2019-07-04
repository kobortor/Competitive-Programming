#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXV = 1e6 + 6;

int freq[MAXV];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        for (int a = 1; a * a <= x; a++) {
            if (x % a == 0) {
                freq[a]++;
                if (a * a != x) {
                    freq[x / a]++;
                }
            }
        }
    }

    for (int a = MAXV - 1;; a--) {
        if (freq[a] >= 2) {
            cout << a;
            return 0;
        }
    }
}
