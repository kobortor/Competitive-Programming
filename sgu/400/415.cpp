#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e4 + 4;

bool good (vector<int> v, int x) {
    bitset<MAXN> bits = 0;
    bits[0] = true;

    for (int vi : v) {
        bits |= bits << vi;
    }

    return bits[x];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    for (int &vi : v) cin >> vi;

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        vector<int> tmp = v;
        tmp.erase(tmp.begin() + i);

        if (!good(tmp, x)) {
            ans.push_back(v[i]);
        }
    }

    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << " ";
    }
}
