#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        vector<int> A(n), B(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i] >> B[i];
        }

        array<ll, 3> prv;
        prv[0] = 0;
        prv[1] = B[0];
        prv[2] = 2 * B[0];
        for (int i = 1; i < n; i++) {
            array<ll, 3> nxt;
            for (int j = 0; j < 3; j++) {
                nxt[j] = LLONG_MAX;
                for (int k = 0; k < 3; k++) {
                    if (A[i] + j != A[i - 1] + k) {
                        nxt[j] = min(nxt[j], prv[k] + j * B[i]);
                    }
                }
            }

            prv = nxt;
        }

        cout << *min_element(allof(prv)) << "\n";
    }
}
