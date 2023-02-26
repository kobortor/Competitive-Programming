#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    string C, S;
    cin >> C >> S;

    string M;
    for (int i = 0; i < (int)C.size(); i++) {
        if (i < (int)S.size()) {
            int x = S[i] - 'A';
            int y = C[i] - 'A';
            int z = (y - x + 26) % 26;
            M.push_back(z + 'A');
        } else {
            // M[k] = M[k - |S|] - C[k]
            int x = M[i - S.size()] - 'A';
            int y = C[i] - 'A';
            int z = (y - x + 26) % 26;
            M.push_back(z + 'A');
        }
    }

    cout << M << endl;
}