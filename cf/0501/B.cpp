#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    map<string, string> ans;

    int q;
    cin >> q;

    while (q--) {
        string x, y;
        cin >> x >> y;
        if (ans.count(x)) {
            string z = ans[x];
            ans.erase(x);
            ans[y] = z;
        } else {
            ans[y] = x;
        }
    }

    cout << ans.size() << "\n";
    for (pair<string, string> p : ans) {
        cout << p.second << " " << p.first << "\n";
    }
}
