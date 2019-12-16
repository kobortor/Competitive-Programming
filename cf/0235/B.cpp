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

    double ans = 0;

    double prv_p, cur_p;
    cin >> cur_p;

    double cur_exp;
    cur_exp = cur_p;
    ans += cur_exp;

    while (--n) {
        prv_p = cur_p;

        cin >> cur_p;

        cur_exp = cur_p * (1 + prv_p + cur_exp);
        ans += cur_exp;
    }

    cout << fixed << setprecision(15) << ans;
}
