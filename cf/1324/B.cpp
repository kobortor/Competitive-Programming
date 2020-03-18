#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> posn(n + 1);
        for (int i = 1; i <= n; i++) {
            int ai;
            cin >> ai;
            posn[ai].push_back(i);
        }

        bool good = false;
        for (int i = 1; i <= n; i++) {
            if ((int)posn[i].size() > 2) {
                good = true;
                break;
            }
            if ((int)posn[i].size() == 2 && posn[i][0] + 1 != posn[i][1]) {
                good = true;
                break;
            }
        }

        if (good) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
