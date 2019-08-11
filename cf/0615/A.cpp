#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<bool> v(m);
    while (n--) {
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            v[x - 1] = true;
        }
    }

    if (count(allof(v), false) == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
