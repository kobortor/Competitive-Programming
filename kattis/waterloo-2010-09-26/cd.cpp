#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    while (true) {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0) {
            break;
        }
        
        vector<int> u(n), v(m);
        for (int &i : u) cin >> i;
        for (int &i : v) cin >> i;

        sort(allof(u));
        sort(allof(v));

        int ans = 0;
        while (!u.empty() && !v.empty()) {
            if (u.back() > v.back()) {
                swap(u, v);
            }

            if (u.back() == v.back()) {
                u.pop_back();
                v.pop_back();
                ans++;
            } else {
                v.pop_back();
            }
        }
        
        cout << ans << "\n";
    }
}
