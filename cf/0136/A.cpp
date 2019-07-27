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

    vector<int> ans(n);
    for (int a = 1, x; a <= n; a++) {
        cin >> x;
        ans[x - 1] = a;
    }

    for (int a = 0; a < n; a++) {
        cout << ans[a] << " ";
    }
}
