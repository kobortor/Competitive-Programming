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

    ll sum = 0;
    vector<int> v(n);
    for (int a = 0; a < n; a++) {
        cin >> v[a];
        sum += v[a];
    }
    sort(allof(v), greater<int>());

    int m;
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        cout << sum - v[x - 1] << "\n";
    }
}
