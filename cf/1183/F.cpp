#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int Q;
    cin >> Q;

    while (Q--) {
        int N;
        cin >> N;

        vector<int> v;
        for (int a = 0, x; a < N; a++) {
            cin >> x;
            v.push_back(x);
        }

        sort(allof(v));
        v.erase(unique(allof(v)), v.end());
        N = v.size();

        int mx = v.back();

        int res1 = 0;
        if (mx % 2 == 0 && mx % 3 == 0 && mx % 5 == 0) {
            if (find(allof(v), mx / 2) != v.end() &&
                find(allof(v), mx / 3) != v.end() &&
                find(allof(v), mx / 5) != v.end()) {
                res1 = mx / 2 + mx / 3 + mx / 5;
            }
        }

        int res2 = 0;
        for (int a = 0; a < 3 && !v.empty(); a++) {
            mx = v.back();
            res2 += mx;
            vector<int> newv;
            for (int i : v) {
                if (mx % i != 0) {
                    newv.push_back(i);
                }
            }

            v.swap(newv);
        }

        cout << max(res1, res2) << "\n";
    }
}
