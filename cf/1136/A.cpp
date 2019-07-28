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
    for (int &i : v) {
        int x;
        cin >> x >> i;
    }

    int k;
    cin >> k;

    cout << n - (lower_bound(allof(v), k) - v.begin());
}
