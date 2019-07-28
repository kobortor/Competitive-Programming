#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    vector<int> v(4);
    for (int &i : v) cin >> i;

    sort(allof(v));

    if (v[0] + v[1] > v[2] || v[1] + v[2] > v[3]) {
        cout << "TRIANGLE";
    } else if (v[0] + v[1] == v[2] || v[1] + v[2] == v[3]) {
        cout << "SEGMENT";
    } else {
        cout << "IMPOSSIBLE";
    }
}
