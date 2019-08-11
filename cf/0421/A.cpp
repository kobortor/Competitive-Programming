#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> v(n);
    while (a--) {
        int x;
        cin >> x;
        v[x - 1] = 1;
    }
    while (b--) {
        int x;
        cin >> x;
        v[x - 1] = 2;
    }

    for (int i : v) cout << i << " ";
}
