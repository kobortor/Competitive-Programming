#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool diff (int x) {
    string s = to_string(x);
    int n = s.size();

    sort(allof(s));
    s.erase(unique(allof(s)), s.end());

    return (int)s.size() == n;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int l, r;
    cin >> l >> r;
    for (int a = l; a <= r; a++) {
        if (diff(a)) {
            cout << a;
            return 0;
        }
    }

    cout << -1;
}
