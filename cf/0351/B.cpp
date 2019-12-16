#include<bits/stdc++.h>

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

    vector<int> v(n);
    for (int &vi : v) {
        cin >> vi;
    }

    // could have done BIT, but this is easier to code
    int inv = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] > v[j]) {
                inv++;
            }
        }
    }

    if (inv & 1) {
        cout << 1 + (inv - 1) * 2;
    } else {
        cout << inv * 2;
    }
}
