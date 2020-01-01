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
    for (int &vi : v) cin >> vi;

    sort(allof(v));
    v.erase(unique(v.begin(), v.end()), v.end());

    if ((int)v.size() <= 2) {
        cout << "YES";
    } else if ((int)v.size() == 3 && v[1] - v[0] == v[2] - v[1]) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
