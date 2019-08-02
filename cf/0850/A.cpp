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

    if (n > 100) {
        cout << 0;
        return 0;
    }
    
    vector<vector<int>> pts(n, vector<int>(5));
    for (vector<int> &v : pts) {
        for (int &i : v) cin >> i;
    }

    vector<int> ans;
    for (int a = 0; a < n; a++) {
        bool good = true;
        for (int b = 0; b < n && good; b++) {
            if (a == b) continue;
            for (int c = 0; c < n; c++) {
                if (a == c || b == c) continue;
                int dot = 0;
                for (int i = 0; i < 5; i++) {
                    dot += (pts[b][i] - pts[a][i]) * (pts[c][i] - pts[a][i]);
                }

                if (dot > 0) {
                    good = false;
                    break;
                }
            }
        }
        if (good) {
            ans.push_back(a + 1);
        }
    }

    cout << ans.size() << "\n";
    for (int i : ans) cout << i << "\n";
}
