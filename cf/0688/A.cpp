#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, d;
    cin >> n >> d;

    int ans = 0;
    int cur = 0;

    while (d--) {
        string s;
        cin >> s;
        if (s != string(n, '1')) {
            cur++;
        } else {
            cur = 0;
        }

        ans = max(ans, cur);
    }

    cout << ans;
}
