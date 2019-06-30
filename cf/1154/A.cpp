#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    vector<int> v;
    for (int a = 0, x; a < 4; a++) {
        cin >> x;
        v.push_back(x);
    }

    int mx = *max_element(allof(v));
    for (int a = 0; a < 4; a++) {
        if (v[a] != mx) {
            cout << mx - v[a] << " ";
        }
    }
}
