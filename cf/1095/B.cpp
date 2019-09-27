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
    for (int &i : v) cin >> i;

    sort(allof(v));

    cout << min(v[n - 2] - v[0], v[n - 1] - v[1]);
}
